# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10222.py
#  Description:     UVa Online Judge - 10222
# =============================================================================
source = " 234567890-=ertyuiop[]\dfghjkl;'cvbnm,./@#$%^&*()_+ERTYUIOP{}|DFGHJKL:\"CVBNM<>?"
target = " `1234567890qwertyuiop[asdfghjklzxcvbnm,~!@#$%^&*()QWERTYUIOP{ASDFGHJKLZXCVBNM<"

mapping = {}
for i in range(len(source)):
    mapping[source[i]] = target[i]

while True:
    try:
        line = input()
    except EOFError:
        break
    
    output = ''.join(list(map(lambda x: mapping[x], line)))
    print(output)