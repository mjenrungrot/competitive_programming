def run():
    lines = []
    for i in range(10):
        lines.append(input())

    embeddings = list(map(lambda x:[lines[k][x] for k in range(1, 9)], range(1, len(lines[0]) - 1)))
    embeddings_bin = [''.join(list(map(lambda x: '0' if x == '/' else '1', embedding))) for embedding in embeddings]
    embeddings_ord = list(map(lambda x: int(x[::-1], base=2), embeddings_bin))
    output = ''.join(list(map(chr, embeddings_ord)))
    print(output)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        if(i):
            _ = input()
        run()