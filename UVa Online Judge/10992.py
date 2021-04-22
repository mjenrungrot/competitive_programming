# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10992.py
#  Description:     UVa Online Judge - 10992
# =============================================================================

nt = 0
while True:
    N = int(input())
    if N == 0: break

    if nt: print("")
    nt += 1
    
    n_ghost = 0
    print(N)
    if (N < 2148):
        print("No ghost will come in this year")
        continue

    if N % 2 == 0: 
        n_ghost += 1
        print("Ghost of Tanveer Ahsan!!!")
    if N % 5 == 3:
        n_ghost += 1
        print("Ghost of Shahriar Manzoor!!!")
    if N % 7 == 6:
        n_ghost += 1
        print("Ghost of Adrian Kugel!!!")
    if N % 11 == 3:
        n_ghost += 1
        print("Ghost of Anton Maydell!!!")
    if N % 15 == 3:
        n_ghost += 1
        print("Ghost of Derek Kisman!!!")
    if N % 20 == 8:
        n_ghost += 1
        print("Ghost of Rezaul Alam Chowdhury!!!")
    if N % 28 == 20:
        n_ghost += 1
        print("Ghost of Jimmy Mardell!!!")
    if N % 36 == 24:
        n_ghost += 1
        print("Ghost of Monirul Hasan!!!")
    if N % 400 == 0 or (N%100 != 0 and N%4 == 0):
        n_ghost += 1
        print("Ghost of K. M. Iftekhar!!!")

    if n_ghost == 0:
        print("No ghost will come in this year")

    