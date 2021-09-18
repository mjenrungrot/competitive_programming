# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10771.py
#  Description:     UVa Online Judge - 10771
# =============================================================================

while True:
    N, M, K = list(map(int, input().split()))
    if N == M == K == 0:
        break

    # G,K => add K => (nG-1,nK)
    # G,G => add G => (nG-1,nK)
    # K,K => add G => (nG+1,nK-2)
    ans = M % 2

    if ans:
        print("Keka")
    else:
        print("Gared")
