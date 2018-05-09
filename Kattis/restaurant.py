"""
Problem: restaurant
Link: https://open.kattis.com/problems/restaurant
Source: Southwestern Europe Regional Contest (SWERC) 2009
"""

space = False
while True:
    N = int(input())
    if N == 0: break

    if space: print("")
    space = True

    stack1 = 0
    stack2 = 0
    for i in range(N):
        command, arg = input().split()
        arg = int(arg)
        if command == 'DROP':
            print('DROP 1 {:}'.format(arg))
            stack1 += arg
        elif command == 'TAKE':
            if stack2 >= arg:
                print("TAKE 2 {:}".format(arg))
                stack2 -= arg
            else:
                if stack2 > 0:
                    print("TAKE 2 {:}".format(stack2))
                    arg -= stack2
                    stack2 = 0
                    print("MOVE 1->2 {:}".format(stack1))
                    stack2 = stack1
                    stack1 = 0
                    print("TAKE 2 {:}".format(arg))
                    stack2 -= arg
                else:
                    print("MOVE 1->2 {:}".format(stack1))
                    stack2 = stack1
                    stack1 = 0
                    print("TAKE 2 {:}".format(arg))
                    stack2 -= arg
