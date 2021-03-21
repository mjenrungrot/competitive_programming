nums = ['0','1','2','3','4','5','6','7','8','9']
row1 = ['.*','*.','*.','**','**','*.','**','**','*.','.*']
row2 = ['**','..','*.','..','.*','.*','*.','**','**','*.']
row3 = ['..','..','..','..','..','..','..','..','..','..']
numToRow1 = dict(zip(nums, row1))
numToRow2 = dict(zip(nums, row2))
numToRow3 = dict(zip(nums, row3))

concatenated_rows = list(map(lambda x: row1[x] + row2[x] + row3[x], range(10)))
concatednatedToNum = dict(zip(concatenated_rows, nums))

while True:
    N = int(input())
    if N == 0: break

    ch = input()

    if ch == 'S':
        data = input()
        print(' '.join(list(map(lambda x: numToRow1[x], data))))
        print(' '.join(list(map(lambda x: numToRow2[x], data))))
        print(' '.join(list(map(lambda x: numToRow3[x], data))))
    else:
        row1_data = input().split()
        row2_data = input().split()
        row3_data = input().split()
        concatenated_data = list(map(lambda x: row1_data[x] + row2_data[x] + row3_data[x], range(N)))
        print(''.join(list(map(lambda x: concatednatedToNum[x], concatenated_data))))