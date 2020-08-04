def convert(ch, mapping):
    if ch in mapping:
        return mapping[ch]
    else:
        return ch

def run():
    plain_text = input()
    substitution_text = input()

    mapping = {}
    for i in range(len(plain_text)):
        mapping[plain_text[i]] = substitution_text[i]

    print(substitution_text)
    print(plain_text)
    while True:
        try:
            line = input()
        except EOFError:
            break
        if len(line) == 0: break

        substituted_line = ''.join(list(map(lambda x: convert(x, mapping), line)))
        print(substituted_line)

if __name__ == '__main__':
    T = int(input())
    _ = input()
    for i in range(T):
        if(i): print("")
        run()
