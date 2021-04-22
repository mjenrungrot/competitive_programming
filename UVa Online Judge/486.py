# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        486.py
#  Description:     UVa Online Judge - 486
# =============================================================================

words = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', \
    'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen', \
    'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety', 'hundred', 'thousand', 'million']
values = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, \
    40, 50, 60, 70, 80, 90, 100, 1000, 1000000]
mapping = dict(zip(words, values))

def parse(tokens):
    ans = 0
    for token in tokens:
        if token >= 100:
            ans *= token
        else:
            ans += token

    return ans

while True:
    try:
        line = input()
    except EOFError:
        break

    negative = False
    tokens = line.split()
    if tokens[0] == 'negative':
        negative = True
        tokens = tokens[1:]

    tokens = list(map(lambda x: mapping[x], tokens))
    ans = 0
    # check million
    for i in range(len(tokens)):
        if tokens[i] == 1000000:
            ans += parse(tokens[:i]) * 1000000
            tokens = tokens[i+1:]
            break

    # check thousand
    for i in range(len(tokens)):
        if tokens[i] == 1000:
            ans += parse(tokens[:i]) * 1000
            tokens = tokens[i+1:]
            break

    ans += parse(tokens)
    if(negative): ans *= -1

    print(ans)