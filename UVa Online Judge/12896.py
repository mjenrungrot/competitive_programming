nums = list(map(int, list('1111222333444555666777788899990')))
t    = list(map(int, list('1234123123123123123123412312341')))
num_t_pair = zip(nums, t)
syms = list('.,?"abcdefghijklmnopqrstuvwxyz ')
mapping = dict(zip(num_t_pair, syms))
T = int(input())

for _ in range(T):
    L = int(input())
    N = list(map(int, input().split()))
    P = list(map(int, input().split()))
    N_P_pair = zip(N, P)
    decoded = ''.join(list(map(lambda x: mapping[x], N_P_pair)))
    print(decoded)    
