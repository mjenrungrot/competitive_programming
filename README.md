# Algorithm

Include all of my accepted submissions onto:

- UVa Online Judge
- ACM ICPC Live Archive
- Codeforces
- Topcoder
- Google Code Jam
- Facebook Hacker Cup
- etc.

## Python tooling

Python formatting and baseline linting use Ruff through pre-commit.

Install the local hook:

```sh
python3 -m pip install -r requirements-dev.txt
pre-commit install
```

Run the checks manually:

```sh
ruff check --fix <path>
ruff format <path>
pre-commit run --files <path>
```

The lint baseline is intentionally limited to parse and undefined-name checks so it can run on the
existing accepted-submission archive without rewriting contest-style code. The generated
`LibraryChecker/**/*.unsolved.py` templates are excluded from the hook because some still contain
problem-statement LaTeX in non-raw docstrings before they are solved.
