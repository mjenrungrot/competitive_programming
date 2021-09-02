# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11278.py
#  Description:     UVa Online Judge - 11278
# =============================================================================

source = list(
    " `1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?"
)
target = list(
    " `123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\""
)
mapping = dict(zip(source, target))

while True:
    try:
        line = input()
    except EOFError:
        break

    print("".join(list(map(lambda x: mapping[x], line))))
