# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        12844.py
#  Description:     UVa Online Judge - 12844
# =============================================================================

T = int(input())
for i in range(T):
    print("Case {}: ".format(i + 1), end="")

    nums = list(map(int, input().split()))
    nums = sorted(nums)

    m3 = sum(nums) // 4 - nums[0] - nums[-1]
    m1 = nums[1] - m3  # m1+m3
    m2 = nums[0] - m1  # m1+m2
    m5 = nums[-2] - m3  # m3+m5
    m4 = nums[-1] - m5  # m4+m5
    print(m1, m2, m3, m4, m5)
