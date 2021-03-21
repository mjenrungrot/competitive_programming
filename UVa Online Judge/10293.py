import re
from collections import Counter

lines = []
while True:
    try:
        line = input().strip()
    except EOFError:
        break
    # print("[{}]".format(line))
    if line == "#":
        long_str = '\n'.join(lines)
        long_str = long_str.replace('-\n', '')
        long_str = long_str.replace('-', '')
        long_str = long_str.replace("'", "")
        words = re.split(" |\?|!|,|\.|\n", long_str)

        ans = Counter(list(filter(lambda x: x > 0,
                      map(lambda x: len(x), words))))
        keys = sorted(ans.keys())
        for key in keys:
            print("{} {}".format(key, ans[key]))
        print("")
        lines = []
    else:
        lines.append(line)