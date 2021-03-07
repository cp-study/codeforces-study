import sys
input = sys.stdin.readline

t = int(input())
for j in range(t):
    n = int(input())
    arr = list(input())
    x = y = 0
    d = {}
    d[(x,y)] = 0
    start = -1
    end = n
    for i in range(n):
        if arr[i] == 'R':
            y+=1
        elif arr[i] == 'L':
            y-=1
        elif arr[i] == 'U':
            x+=1
        elif arr[i] == 'D':
            x-=1
        if (x,y) in d:
            if i-d[(x,y)] < end-start:
                end = i
                start = d[(x,y)]
        d[(x,y)] = i+1
    if start == -1:
        print(-1)
    else:
        print(start+1,end+1)
