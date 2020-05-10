"""
Problem: Nesting Depth
Google Codejam - Qualification Round 2020
Link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f?show=progress
"""
def run(idx):
    S = input().strip()

    output = ""
    counter = 0
    for i in range(len(S)):
        if S[i] == '0':
            if counter == 0:
                output += S[i]
            else:
                while counter > 0:
                    counter -= 1
                    output += ')'
                output += S[i]
        else:
            if counter < int(S[i]):
                while counter < int(S[i]):
                    counter += 1
                    output += '('
                output += S[i]
            else:
                while counter > int(S[i]):
                    counter -= 1
                    output += ')'
                output += S[i]

    while counter > 0:
        counter -= 1
        output += ')'

    print("Case #{}: {}".format(idx, output))

if __name__ == '__main__':
    T = int(input())
    for i in range(1, T+1):
        run(i)
