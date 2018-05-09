"""
Problem: catcoat
Link: https://open.kattis.com/problems/catcoat
Source: Kattis / Spotify Challenge 2011
"""

possibilities = {
    'Black': ['B-D-oo', 'B-D-o'],
    'Blue': ['B-ddoo', 'B-ddo'],
    'Chocolate': ['bbD-oo', 'bbD-o'],
    'Lilac': ['bbddoo', 'bbddo'],
    'Red': ['--D-OO', '--D-O'],
    'Cream': ['--ddOO', '--ddO'],
    'Black-Red Tortie': ['B-D-Oo'],
    'Blue-Cream Tortie': ['B-ddOo'],
    'Chocolate-Red Tortie': ['bbD-Oo'],
    'Lilac-Cream Tortie': ['bbddOo'],
}

def match(combination, code):
    if(len(combination) != len(code)): return False
    for i in range(len(combination)):
        if(code[i] == '-'): continue
        if(combination[i] != code[i]): return False
    return True

def search(combination):
    for key in possibilities.keys():
        for code in possibilities[key]:
            if(match(combination,code)): return key
    return "error"

def convert(code):
    if code == 'oO': return 'Oo'
    if code == 'bB': return 'Bb'
    if code == 'dD': return 'Dd'
    return code

colorFemale = input()
colorMale = input()

def generatePossibilities(blacks, dilutions, redFemales, redMales):
    counter = []
    for black in blacks:
        for dilution in dilutions:
            for redFemale in redFemales:
                combination = black + dilution + redFemale
                counter.append(combination)
            for redMale in redMales:
                combination = black + dilution + redMale
                counter.append(combination)
    return counter


combinationPossibilities = []
for blackFemale in ['BB', 'Bb', 'bb']:
    for dilutionFemale in ['DD', 'Dd', 'dd']:
        for redFemale in ['OO', 'Oo', 'oo']:
            combinationFemale = blackFemale + dilutionFemale + redFemale
            if search(combinationFemale) != colorFemale: continue
            for blackMale in ['BB', 'Bb', 'bb']:
                for dilutionMale in ['DD', 'Dd', 'dd']:
                    for redMale in ['O', 'o']:
                        combinationMale = blackMale + dilutionMale + redMale
                        if search(combinationMale) != colorMale: continue

                        blackPossiblities = [convert(blackFemale[0] + blackMale[0]),
                                             convert(blackFemale[0] + blackMale[1]),
                                             convert(blackFemale[1] + blackMale[0]),
                                             convert(blackFemale[1] + blackMale[1])]
                        dilutionPossiblities = [convert(dilutionFemale[0] + dilutionMale[0]),
                                                convert(dilutionFemale[0] + dilutionMale[1]),
                                                convert(dilutionFemale[1] + dilutionMale[0]),
                                                convert(dilutionFemale[1] + dilutionMale[1])]
                        # Female case
                        redFemalePossibilities = [convert(redFemale[0] + redMale[0]),
                                                  convert(redFemale[1] + redMale[0])]
                        # Male case
                        redMalePossibilities = [redFemale[0], redFemale[1]]

                        combinationPossibilities += generatePossibilities(blackPossiblities, dilutionPossiblities, redFemalePossibilities, redMalePossibilities)

combinationPossibilities = [search(combination) for combination in combinationPossibilities]

dictCounter = dict()
for key in possibilities.keys():
    dictCounter[key] = 0
for color in combinationPossibilities:
    dictCounter[color] += 1

answerList = sorted(dictCounter.items(), key=lambda t: (-t[1],t[0]))
for answer in answerList:
    if(answer[1] == 0): break
    print("{:} {:.10f}".format(answer[0], answer[1] / len(combinationPossibilities)))
