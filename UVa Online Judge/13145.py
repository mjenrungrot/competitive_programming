while True:
    N = int(input())
    if N == 0: break

    line = input()
    converter = lambda x: \
        chr(ord('a') + (ord(x) - ord('a') + N) % 26) if ord('a') <= ord(x) <= ord('z') else \
        chr(ord('A') + (ord(x) - ord('A') + N) % 26) if ord('A') <= ord(x) <= ord('Z') else \
        x
    output = ''.join(list(map(converter, line)))
    print(output)