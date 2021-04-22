# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        641.py
#  Description:     UVa Online Judge - 641
# =============================================================================

def textToCode(ch):
    if ch == '_': return 0
    if ch == '.': return 27
    return ord(ch) - ord('a') + 1

def codeToText(code):
    if code == 0: return '_'
    if code == 27: return '.'
    return chr(ord('a') + code - 1)

while True:
    line = input().split()
    k = int(line[0])
    if k == 0: break

    n = len(line[1])
    ciphertext = line[1]
    ciphercode = list(map(textToCode, ciphertext))

    plaincode = [0 for _ in range(len(ciphercode))]
    for i in range(len(ciphercode)):
        plaincode[(k*i) % n] = (ciphercode[i] + i) % 28

    plaintext = ''.join(list(map(codeToText, plaincode)))

    print(plaintext)