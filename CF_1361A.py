import sys
r=sys.stdin.buffer.readline
n,m=map(int,r().split())
network=[[] for _ in range(n)]
for _ in range(m):
    a,b=map(int,r().split())
    network[a-1].append(b-1)
    network[b-1].append(a-1)
lst=list(map(int,r().split()))
arr=list(range(n))
arr.sort(key=lambda x: lst[x])
ret=[1]*n
res=[]
for i in arr:
    t=lst[i]
    if t==ret[i]:
        for j in network[i]:
            if ret[j]==t:
                ret[j]+=1
        res.append(i+1)
    else:
        print(-1)
        exit(0)
print(*res)
