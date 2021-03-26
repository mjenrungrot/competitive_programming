T = int(input())

while T > 0:
    T -= 1
    nums = input().split()

    n_fraction_max = 0
    for i in range(len(nums)):
        if nums[i].find('.') == -1:
            n_fraction = 0
        else:
            n_fraction = len(nums[i]) - nums[i].find('.') - 1
        n_fraction_max = max(n_fraction_max, n_fraction)

    for i in range(len(nums)):
        if nums[i].find('.') == -1:
            n_fraction = 0
        else:
            n_fraction = len(nums[i]) - nums[i].find('.') - 1
        nums[i] += "0" * (n_fraction_max - n_fraction)
        nums[i] = int(nums[i].replace('.', ''))
    
    sum_val = 0
    for i in range(len(nums)):
        sum_val += nums[i]
    
    negative = sum_val < 0
    sum_val = abs(sum_val)
    digits = sum_val // (10 ** n_fraction_max)
    fractions = sum_val % (10 ** n_fraction_max)

    digits = str(digits)
    fractions = str(fractions)
    fractions = fractions[::-1]
    fractions += "0" * (n_fraction_max - len(fractions))
    fractions = fractions[::-1]
    fractions = fractions.rstrip('0')

    if negative: print("-", end="")
    if len(fractions) == 0:
        print("{}.0".format(digits))
    else:
        print("{}.{}".format(digits, fractions))