A_I_LIMIT = 8005

def run():
    N = int(input())
    data = list(map(int, input().split()))

    counter = [0 for i in range(A_I_LIMIT)]
    for x in data:
        counter[x] += 1

    ans = 0
    for l in range(len(data)):
        sum = data[l]
        for r in range(l+1, len(data)):
            sum += data[r]
            if sum > N:
                break
            if counter[sum]:
                ans += counter[sum]
                counter[sum] = 0
    print(ans)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()