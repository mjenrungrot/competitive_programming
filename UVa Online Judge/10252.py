from collections import Counter

while True:
    try:
        line1 = input()
    except EOFError:
        break

    line2 = input()

    counter1 = Counter(line1)
    counter2 = Counter(line2)
    
    for ch in range(26):
        ch = chr(ord('a') + ch)
        if (ch in counter1) and (ch in counter2):
            min_val = min(counter1[ch], counter2[ch])
            print('{}'.format(ch) * min_val, end="")

    print("")