import re
import math

def parse(num):
    if num[0] != '':
        l, r = num[0].split('-')
        r_top, r_bottom = r.split('/')
        return (int(r_bottom) * int(l) + int(r_top), int(r_bottom))
    elif num[1] != '':
        num = num[1].split('/')
        return (int(num[0]), int(num[1]))
    else:
        return (int(num[2]), 1)

def run():
    line = input()

    nums = re.findall(r"(\d+-\d+\/\d+)|(\d+\/\d+)|(\d+)", line)
    nums = list(map(parse, nums))

    ans = (1,1)
    for num in nums:
        ans = (ans[0] * num[0], ans[1] * num[1])
        gg = math.gcd(ans[0], ans[1])
        ans = (ans[0] // gg, ans[1] // gg)

    if ans[1] == 1:
        print(ans[0])
    elif ans[0] < ans[1]:
        print("{}/{}".format(ans[0], ans[1]))
    else:
        print("{}-{}/{}".format(ans[0] // ans[1], ans[0] % ans[1], ans[1]))

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()