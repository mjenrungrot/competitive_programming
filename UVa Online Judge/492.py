while True:
    try:
        line = input()
    except EOFError:
        break

    word = ""
    curr = 0
    while curr < len(line):
        if line[curr].isalpha():
            word += line[curr]
        else:
            if len(word) > 0:
                if word[0] in 'aeiouAEIOU': word = word + "ay"
                else: word = word[1:] + word[0] + "ay"
                print(word, end="")
            print(line[curr], end="")
            word = ""
        curr += 1

    if len(word) > 0:
        if word[0] in 'aeiouAEIOU': word = word + "ay"
        else: word = word[1:] + word[0] + "ay"
        print(word)
    else:
        print("")