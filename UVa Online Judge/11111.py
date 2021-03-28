while True:
    try:
        nums = list(map(int, input().split()))
    except EOFError:
        break

    stack1 = []
    stack2 = []
    curr = 0
    length = len(nums)
    fail = False
    while curr < length:
        x = nums[curr]
        if x < 0:
            stack1.append(x)
            stack2.append(-x)
        else:
            if len(stack1) == 0 or stack1[-1] + x != 0:
                fail = True
                break
            
            stack2.pop()
            stack1.pop()

            if len(stack1) > 0:
                s = stack2.pop() - x
                if s <= 0: 
                    fail = True
                    break
                stack2.append(s)

        curr += 1

    if len(stack1) > 0: fail = True
    if fail: print(":-( Try again.")
    else: print(":-) Matrioshka!")