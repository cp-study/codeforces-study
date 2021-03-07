import sys
input = sys.stdin.readline

t = int(input())
for j in range(t):
    n = int(input())
    arr = list(input())
    x = y = 0
    d = {}
    d[(x,y)] = 0
    l = -1
    r = n
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
            if i-d[(x,y)] < r-l:
                r = i
                l = d[(x,y)]
        d[(x,y)] = i+1
    if l == -1:
        print(-1)
    else:
        print(l+1,r+1)
