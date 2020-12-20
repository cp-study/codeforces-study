import sys
r=sys.stdin.buffer.readline
n=int(r())
arr=list(map(int,r().split()))
bits=[sum((x>>i)&1 for x in arr) for i in range(20)]
answer=0
for i in range(n):
    tmp=sum(1<<j for j,v in enumerate(bits) if v>i)
    answer+=tmp**2
print(answer)