import sys
input = sys.stdin.readline

n,m,k = map(int,input().split())

for i in range(k):
    a,b = map(int,input().split())
for i in range(k):
    a,b = map(int,input().split())

ans = []
for i in range(n-1):
    ans.append("U")
for i in range(m-1):
    ans.append("L")
for i in range(n):
    if i%2==0:
        for j in range(m-1):
            ans.append("R")
    else:
        for j in range(m-1):
            ans.append("L")
    ans.append("D")
print(len(ans))
print(''.join(ans))
