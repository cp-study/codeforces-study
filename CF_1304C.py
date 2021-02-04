import sys
input = sys.stdin.readline

for i in range(int(input())):
    n,m = map(int,input().split())
    arr = []
    for j in range(n):
        arr.append(list(map(int,input().split())))
    prev = 0
    Min = Max = m
    flag = True
    for j in arr:
        Min -= j[0] - prev
        Max += j[0] - prev
        if Max < j[1] or Min > j[2]:
            flag = False
            break
        Min = max(Min,j[1])
        Max = min(Max,j[2])
        prev = j[0]
    if flag:
        print("YES")
    else:
        print("NO")
