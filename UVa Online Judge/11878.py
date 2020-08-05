ans = 0

while True:
    try:
        line = input()
    except EOFError:
        break

    lhs, rhs = line.split('=')

    lhs_eval = eval(lhs)
    if '?' in rhs: continue
    rhs_eval = eval(rhs)
    if lhs_eval == rhs_eval: ans += 1

print(ans)