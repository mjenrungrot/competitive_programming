def processTime(timeStr):
    hh, mm, ss = list(map(int, timeStr.split(':')))
    return hh * 3600 + mm * 60 + ss

def computeCost(score):
    mapping = {
        0: 6,
        1: 2,
        2: 5,
        3: 5,
        4: 4,
        5: 5,
        6: 6,
        7: 3,
        8: 7,
        9: 6,
    }
    cost = 0
    digit100 = score // 100
    if score >= 100: cost += mapping[digit100]
    digit10 = (score % 100) // 10
    if score >= 10: cost += mapping[digit10]
    digit1 = score % 10
    cost += mapping[digit1]
    return cost

if __name__ == '__main__':
    case_no = 1
    while True:
        try:
            line = input()
        except EOFError:
            break

        line = line.split()
        curr_time = processTime(line[1])
        home_score = 0
        guest_score = 0
        cost = 0
        
        while True:
            line = input().split()
            time = processTime(line[1])
            
            cost += (time - curr_time) * (computeCost(home_score) + computeCost(guest_score))
            
            if line[0] == 'END': break
            if line[2] == 'home': home_score += int(line[-1])
            else: guest_score += int(line[-1])
            curr_time = time

        print("Case {}: {}".format(case_no, cost))
        case_no += 1