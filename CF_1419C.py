t = int(input())
for i in range(t):
    n,x = map(int,input().split())
    arr = list(map(int,input().split()))
    Sum = sum(arr)
    cnt = 0
    for i in arr:
        if i == x:
            cnt+=1
    if cnt == n:
        print(0)
    elif cnt >= 1 or Sum==n*x:
        print(1)
    else:
        print(2)
