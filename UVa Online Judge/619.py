def get_comma(num):
    output = ""
    num = str(num)[::-1]

    i = 0
    while i < len(num):
        output += num[i]
        i += 1
        if i >= len(num): break
        if i % 3 == 0: output += ','
        
    return output[::-1]


while True:
    line = input()
    if line == "*": break


    if ord('0') <= ord(line[0]) <= ord('9'):
        ans = ""
        num = int(line)
        curr = num
        while curr > 0:
            if curr % 26: offset = curr % 26
            else: offset = 26
            ans += chr(ord('a') + offset - 1)
            curr -= offset
            curr //= 26
        ans = ans[::-1]

        print("{:22s}{:}".format(ans, get_comma(num)))
    else:
        ans = 0
        for i in range(len(line)):
            ans *= 26
            ans += ord(line[i]) - ord('a') + 1
        
        print("{:22s}{:}".format(line, get_comma(ans)))