
def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

def run():
    N = int(input())
    data = []
    for _ in range(N):
        A, B = list(map(int, input().split()))
        data.append((A, B))

    unique_ratios = set()
    for i in range(N):
        for j in range(i+1, N):
            if data[i][0] < data[j][0] and data[i][1] < data[j][1]:
                continue
            if data[i][0] > data[j][0] and data[i][1] > data[j][1]:
                continue
            if data[i][0] == data[j][0]:
                continue
            if data[i][1] == data[j][1]:
                continue

            ratio = (abs(data[i][0] - data[j][0]), abs(data[i][1] - data[j][1]))
            common_factor = gcd(ratio[0], ratio[1])
            ratio = (ratio[0] // common_factor, ratio[1] // common_factor)
            # print("({}) ({}) => {}".format(data[i], data[j], ratio))
            unique_ratios.add(ratio)

    print(len(unique_ratios) + 1)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case #{}: ".format(i+1), end="")
        run()