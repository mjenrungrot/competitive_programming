# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10896.py
#  Description:     UVa Online Judge - 10896
# =============================================================================

def test(enc_word, dec_word, k):
    source = [chr(i + ord('a')) for i in range(26)]
    target = [chr((i + k) % 26 + ord('a')) for i in range(26)]
    mapping = dict(zip(source, target))

    enc_word_decrypted = ''.join(list(map(lambda x: mapping[x], enc_word)))
    # print(enc_word, dec_word, k, enc_word_decrypted)
    if enc_word_decrypted == dec_word: return True
    return False


def run():
    encrypted_words = input().split()
    decrypted_word = input()

    ans = ""
    for i in range(26, 0, -1):
        working = False
        for enc_word in encrypted_words:
            if test(enc_word, decrypted_word, i % 26):
                working = True
                break

        if working:
            ans += "{}".format(chr((26 - i) % 26 + ord('a')))
    print(ans)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()