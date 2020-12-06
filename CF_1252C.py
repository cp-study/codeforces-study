import sys
r=sys.stdin.readline
N,Q=map(int,r().split())
R=list(map(int,r().split()))
C=list(map(int,r().split()))
rows=[x for x in range(N)]
cols=[x for x in range(N)]

def find(X:int,lst:list):    #get parent
    if lst[X]==X:
        return X
    lst[X]=find(lst[X],lst)
    return lst[X]
def union(X:int,Y:int,lst:list): #union two coords
    a=find(X,lst)
    b=find(Y,lst)
    if a==b:
        return 
    lst[Y]=a
def get(x,y):
    #get x row, y col cell number
    return R[x]+C[y]

curR=-1
curC=-1
for i in range(N):
    if curR==-1:
        curR=i
    else:
        if R[curR]%2-R[i]%2==0:
            union(curR,i,rows)
        else:
            curR=i
    if curC==-1:
        curC=i
    else:
        if C[curC]%2-C[i]%2==0:
            union(curC,i,cols)
        else:
            curC=i

for _ in range(Q):
    Ra,Ca,Rb,Cb=list(map(int,r().split()))
    if find(Ra-1,rows)==find(Rb-1,rows) and find(Ca-1,cols)==find(Cb-1,cols):
        print("YES")
    else:
        print("NO")
