# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        11483.py
#  Description:     UVa Online Judge - 11483
# =============================================================================
n_test = 0
while True:
    N = int(input())
    if N == 0:
        break

    n_test += 1
    print(f"Case {n_test}:")
    print("#include<string.h>")
    print("#include<stdio.h>")
    print("int main()")
    print("{")

    for _ in range(N):
        S = input()
        S = S.replace("\\", "\\\\")
        S = S.replace("\"", "\\\"")
        print(f"printf(\"{S}\\n\");")
    print("printf(\"\\n\");")
    print("return 0;")
    print("}")