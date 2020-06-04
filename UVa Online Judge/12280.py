def computeScore(num):
    if num < ord('A') or num > ord('Z'):
        return 0

    count1 = 0
    count_all = 0
    while(num > 0):
        count1 += (num % 2)
        count_all += 1
        num = num // 2
    return 250 * (count_all - count1) + 500 * count1

def run():
    A = []
    for i in range(7):
        A.append(input().strip())
    _ = input()

    weightLeft = 0
    weightRight = 0
    labels = []
    for j in range(18):
        filled_label = False
        for i in range(7):
            score = computeScore(ord(A[i][j]))
            if j < 8: weightLeft += score
            else: weightRight += score

            if A[i][j] == '_':
                labels.append(A[i-1][j])
                filled_label = True
        if not filled_label:
            labels.append('.')

    if weightLeft > weightRight:
        if A[6][1] == '_' and A[4][11] == '_':
            print("The figure is correct.")
        else:
            print("........||.../\...\n" + \
                  "........||../..\..\n" + \
                  ".../\...||./....\.\n" + \
                  "../..\..||/{:}\\\n".format(''.join(labels[11:17])) + \
                  "./....\.||\______/\n" + \
                  "/{:}\||........\n".format(''.join(labels[1:7])) + \
                  "\______/||........")

    elif weightLeft == weightRight:
        if A[5][1] == '_' and A[5][11] == '_':
            print("The figure is correct.")
        else:
            print("........||........\n" + \
                  ".../\...||.../\...\n" + \
                  "../..\..||../..\..\n" + \
                  "./....\.||./....\.\n" + \
                  "/{:}\||/{:}\\\n".format(''.join(labels[1:7]), ''.join(labels[11:17])) + \
                  "\______/||\______/\n" + \
                  "........||........")
    else:
        if A[4][1] == '_' and A[6][11] == '_':
            print("The figure is correct.")
        else:
            print(".../\...||........\n" + \
                  "../..\..||........\n" + \
                  "./....\.||.../\...\n" + \
                  "/{:}\||../..\..\n".format(''.join(labels[1:7])) + \
                  "\______/||./....\.\n" + \
                  "........||/{:}\\\n".format(''.join(labels[11:17])) + \
                  "........||\______/")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case {}:".format(i+1))
        run()