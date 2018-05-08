"""
Problem: natrij
Link: https://open.kattis.com/problems/natrij
Source: Croatian Open Competition in Informatics 2006/2007, contest #5
"""
T1 = list(map(int,input().split(':')))
T2 = list(map(int,input().split(':')))

T1_int = int(T1[0]*3600 + T1[1]*60 + T1[2])
T2_int = int(T2[0]*3600 + T2[1]*60 + T2[2])

answer_int = T2_int - T1_int if T2_int > T1_int else T2_int - T1_int + 24 * 3600
answer_hr = answer_int // 3600
answer_min = (answer_int % 3600) // 60
answer_sec = answer_int % 60
print("{:02}:{:02}:{:02}".format(answer_hr, answer_min, answer_sec))
