source = list("BUSPFTM")
target = [1, 10, 100, 1000, 10000, 100000, 1000000]
mapping = dict(zip(source, target))

def run():
    line = input()
    values = list(map(lambda x: mapping[x], line))

    increasing = True
    decreasing = True
    for i in range(len(values) - 1):
        if values[i] > values[i+1]: increasing = False
        if values[i] < values[i+1]: decreasing = False

    if increasing or decreasing:
        counter = 0
        for i in range(len(values)):
            if i == 0 or values[i] == values[i-1]:
                counter += 1
                if counter >= 10:
                    print("error")
                    return
            else:
                counter = 1

        print(sum(values))
    else:
        print("error")

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        run()