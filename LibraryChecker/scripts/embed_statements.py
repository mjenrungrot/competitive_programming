#!/usr/bin/env python3
import re
import sys
from pathlib import Path

ROOT = Path('.cache/library-checker-problems-master')
sys.path.insert(0, str(ROOT))
import toml  # type: ignore


def load_slug_meta():
    meta = {}
    for info_path in ROOT.rglob('info.toml'):
        prob_dir = info_path.parent
        slug = prob_dir.name
        task_md = prob_dir / 'task.md'
        try:
            info = toml.load(info_path)
        except Exception:
            info = {}
        meta[slug] = {
            'task': task_md if task_md.exists() else None,
            'params': info.get('params', {}),
            'title': info.get('title') or info.get('title_en') or slug,
        }
    return meta


LANG_EN = '@{lang.en}'
LANG_JA = '@{lang.ja}'
LANG_END = '@{lang.end}'
SEC_RE = re.compile(r'^## @\{keyword\.[^}]+\}', re.M)
PARAM_RE = re.compile(r'@\{param\.([A-Za-z0-9_]+)\}')
MACRO_LINE_RE = re.compile(r'^\s*@\{[^}]+\}\s*$', re.M)


def substitute_params(text: str, params: dict) -> str:
    return PARAM_RE.sub(lambda m: str(params.get(m.group(1), m.group(0))), text)


def strip_macro_only_lines(text: str) -> str:
    return MACRO_LINE_RE.sub('', text).strip('\n')


def extract_english_block(text: str) -> str:
    i = text.find(LANG_EN)
    if i == -1:
        # Fallback: take the first section (statement) body
        m = list(SEC_RE.finditer(text))
        if not m:
            return strip_macro_only_lines(text)
        # find the statement header
        start = 0
        for mm in m:
            if mm.group(0).startswith('## @{keyword.statement}'):
                start = mm.end()
                break
        nxt = None
        for mm in m:
            if mm.start() > start:
                nxt = mm.start()
                break
        chunk = text[start:nxt] if nxt is not None else text[start:]
        return strip_macro_only_lines(chunk)
    start = i + len(LANG_EN)
    end_candidates = [p for p in (text.find(LANG_JA, start), text.find(LANG_END, start)) if p != -1]
    end = min(end_candidates) if end_candidates else len(text)
    return strip_macro_only_lines(text[start:end])


def _extract_lang_en_from_chunk(chunk: str) -> str:
    i = chunk.find(LANG_EN)
    if i != -1:
        start = i + len(LANG_EN)
        end_candidates = [p for p in (chunk.find(LANG_JA, start), chunk.find(LANG_END, start)) if p != -1]
        end = min(end_candidates) if end_candidates else len(chunk)
        return strip_macro_only_lines(chunk[start:end])
    # no explicit lang blocks - just strip macro-only lines
    return strip_macro_only_lines(chunk)


def extract_section(text: str, header: str) -> str:
    i = text.find(header)
    if i == -1:
        return ''
    start = i + len(header)
    m = SEC_RE.search(text, pos=start)
    end = m.start() if m else len(text)
    chunk = text[start:end]
    return _extract_lang_en_from_chunk(chunk)


def build_docstring(slug: str, category: str, meta: dict) -> str:
    link = f"https://judge.yosupo.jp/problem/{slug}"
    task = meta.get(slug, {}).get('task')
    if not task:
        return ''
    raw = task.read_text(encoding='utf-8')
    params = meta.get(slug, {}).get('params', {})
    title = meta.get(slug, {}).get('title', slug)

    statement = extract_english_block(raw)
    constraints = extract_section(raw, '## @{keyword.constraints}')
    input_ = extract_section(raw, '## @{keyword.input}')
    output_ = extract_section(raw, '## @{keyword.output}')

    statement = substitute_params(statement, params)
    constraints = substitute_params(constraints, params)
    input_ = substitute_params(input_, params)
    output_ = substitute_params(output_, params)

    parts = [
        f"Title: {title}",
        f"Link: {link}",
        f"Category: {category}",
    ]
    if statement:
        parts.append('\nStatement:\n' + statement.strip())
    if constraints:
        parts.append('\nConstraints:\n' + constraints.strip())
    if input_:
        parts.append('\nInput:\n' + input_.strip())
    if output_:
        parts.append('\nOutput:\n' + output_.strip())

    body = '\n\n'.join(parts).rstrip() + '\n'
    return '"""\n' + body + '"""\n'


def main():
    meta = load_slug_meta()
    categories = [
        'big_integer','convolution','data_structure','enumerative_combinatorics','geometry','graph',
        'linear_algebra','number_theory','other','polynomial','sample','set_power_series','string','tree'
    ]
    updated = 0
    for cat in categories:
        cat_dir = Path(cat)
        if not cat_dir.is_dir():
            continue
        # Pretty name
        pretty = 'Set Power Series' if cat == 'set_power_series' else cat.replace('_', ' ').title()
        for py in cat_dir.glob('*.py'):
            slug = py.stem
            doc = build_docstring(slug, pretty, meta)
            if not doc:
                continue
            txt = py.read_text(encoding='utf-8')
            # Remove existing inserted docstring if any (between the first triple quotes pair)
            new_txt = txt
            if '"""' in txt:
                first = txt.find('"""')
                second = txt.find('"""', first + 3)
                if first != -1 and second != -1:
                    new_txt = txt[:first] + txt[second+3:]
            # Find insertion point after leading comment block
            lines = new_txt.splitlines()
            idx = 0
            while idx < len(lines) and lines[idx].startswith('#'):
                idx += 1
            if idx < len(lines) and lines[idx].strip() == '':
                idx += 1
            rebuilt = '\n'.join(lines[:idx]) + ('\n' if idx>0 else '') + doc + '\n'.join(lines[idx:])
            if rebuilt != txt:
                py.write_text(rebuilt, encoding='utf-8')
                updated += 1
    print({'updated': updated})


if __name__ == '__main__':
    main()
