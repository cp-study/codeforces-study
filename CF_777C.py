import sys
rr=sys.stdin.readline
n,m=map(int,rr().split())
table=[]
for _ in range(n):
    table.append(list(map(int,rr().split())))
depth=[[1]*m for _ in range(n)]
for c in range(m):
    for r in range(1,n):
        if table[r][c]>=table[r-1][c]:
            depth[r][c]=depth[r-1][c]+1
max_depth=[max(row) for row in depth]

for _ in range(int(rr())):
    l,r=map(int,rr().split())
    if l==r:
        print("Yes")
    else:
        if max_depth[r-1]>=r-l+1:
            print("Yes")
        else:
            print("No")