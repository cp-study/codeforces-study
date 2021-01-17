import sys
r=sys.stdin.readline
n,k=map(int,r().split())
rooms=list(r().strip())
def nextRoom(i):
    i+=1
    while i<n and rooms[i]=='1':
        i+=1
    return i
l=nextRoom(-1)
r,m=l,l
ans=sys.maxsize
for i in range(k):
    r=nextRoom(r)
while r<n:
    while max(m-l,r-m)>max(nextRoom(m)-l,r-nextRoom(m)):
        m=nextRoom(m)
    ans=min(ans,max(m-l,r-m))
    l,r=nextRoom(l),nextRoom(r)
print(ans)