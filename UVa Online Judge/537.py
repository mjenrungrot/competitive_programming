# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        537.py
#  Description:     UVa Online Judge - 537
# =============================================================================
import re

def run():
    line = input().split('=')

    var1 = line[0][-1]
    num1 = re.match(r'((\-)?(\d+(\.\d*)?))([mkM]?)', line[1]).group(0)
    if 'M' in num1: num1 = float(re.match(r'((\-)?(\d+(\.\d*)?))', line[1]).group(0)) * 1e6
    elif 'k' in num1: num1 = float(re.match(r'((\-)?(\d+(\.\d*)?))', line[1]).group(0)) * 1e3
    elif 'm' in num1: num1 = float(re.match(r'((\-)?(\d+(\.\d*)?))', line[1]).group(0)) * 1e-3
    else: num1 = float(num1)

    var2 = line[1][-1]
    num2 = re.match(r'((\-)?(\d+(\.\d*)?))([mkM]?)', line[2]).group(0)
    if 'M' in num2: num2 = float(re.match(r'((\-)?(\d+(\.\d*)?))', line[2]).group(0)) * 1e6
    elif 'k' in num2: num2 = float(re.match(r'((\-)?(\d+(\.\d*)?))', line[2]).group(0)) * 1e3
    elif 'm' in num2: num2 = float(re.match(r'((\-)?(\d+(\.\d*)?))', line[2]).group(0)) * 1e-3
    else: num2 = float(num2)

    if (var1, var2) == ('P', 'U'): print("I={:.2f}A".format(num1/num2)) 
    elif (var1, var2) == ('U', 'P'): print("I={:.2f}A".format(num2/num1)) 
    elif (var1, var2) == ('P', 'I'): print("U={:.2f}V".format(num1/num2)) 
    elif (var1, var2) == ('I', 'P'): print("U={:.2f}V".format(num2/num1))
    else: print("P={:.2f}W".format(num1*num2))

T = int(input())
for i in range(T):
    print("Problem #{}".format(i+1))
    run()
    print("")