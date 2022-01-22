# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        10393.py
#  Description:     UVa Online Judge - 10393
# =============================================================================
maps = {
    1: list("qaz"),
    2: list("wsx"),
    3: list("edc"),
    4: list("rfvtgb"),
    7: list("yhnujm"),
    8: list("ik,"),
    9: list("ol."),
    10: list("p;/"),
}
reversed_map = {}
for key in maps:
    for val in maps[key]:
        reversed_map[val] = key

while True:
    try:
        N, P = list(map(int, input().split()))
    except:
        break

    nums = []
    while len(nums) < N:
        test = list(map(int, input().split()))
        nums.extend(test)

    assert len(nums) == N
    nums = set(nums)

    best_length = -1
    possible_words = []
    for i in range(P):
        original_word = input()
        test = list(filter(lambda x: x not in nums, \
            list(map(reversed_map.get, list(original_word)))))

        if len(test) == len(original_word):
            if len(original_word) > best_length:
                best_length = len(original_word)
                possible_words = []
            
            if len(original_word) == best_length:
                possible_words.append(original_word)
    
    possible_words = sorted(list(set(possible_words)))

    print(len(possible_words))
    for word in possible_words:
        print(word)
