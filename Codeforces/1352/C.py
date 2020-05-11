def countdivisible(n, divisor):
    return n // divisor

def run():
    n, k = list(map(int, input().split()))

    curr = max(k, (k-1) * n // (n-1))
    while True:
        if curr - countdivisible(curr, n) == k:
            print(curr)
            break
        curr += 1


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()