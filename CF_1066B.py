n,r = map(int,input().split())
arr = list(map(int,input().split()))
ans = 0
last = -1
while last < n-1:
    pos = -1
    for i in range(n-1,max(-1,last-r+1),-1):
        if arr[i] == 1 and i-r <= last:
            pos = i
            break
    if pos == -1:
        print(-1)
        exit()
    ans+=1
    last = pos+r-1
print(ans)
