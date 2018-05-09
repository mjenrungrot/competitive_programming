"""
Problem: addingwords
Link: https://open.kattis.com/problems/addingwords
Source: Kattis
"""
import sys

lines = sys.stdin
memory = dict()


def define(variable, value):
    memory[variable] = value

def calc(args):
    for i in range(0, len(args), 2):
        if args[i] not in memory:
            return "unknown"
        else:
            args[i] = str(memory[args[i]])

    expr = "".join(args)
    value = eval(expr)
    for (variable, val) in memory.items():
        if val == value:
            return variable
    return "unknown"

def clear():
    memory.clear()

def process(line):
    line = line.split()
    command, args = line[0], line[1:]
    if command == 'def':
        define(args[0], int(args[1]))
    elif command == 'calc':
        output = calc(args[:-1])
        print("{:} = {:}".format(" ".join(args[:-1]), output))
    elif command == 'clear':
        clear()

for line in lines:
    process(line)
