import math

def run():
    N = int(input())

    ans = 0
    while N >= 2:
        height = int(math.floor((-0.5 + math.sqrt(0.25 + 6*N)) / 3.0))
        amount = 3 * height * (height + 1) // 2 - height
        N -= amount
        ans += 1

    print(ans)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()