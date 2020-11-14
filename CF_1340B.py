import sys
r=sys.stdin.readline
n,k=map(int,r().split())
seg0to9=[
    "1110111", "0010010", "1011101",
    "1011011", "0111010", "1101011",
    "1101111", "1010010", "1111111", "1111011"
]#0~9
ck=[[-1]*10 for _ in range(n)]
def bit_count(n):
    k=0
    cnt=0
    while n>=(1<<k):
        if n&(1<<k)!=0:
            cnt+=1
        k+=1
    return cnt
for i in range(n):
    cur=r().strip()
    for j,seg in enumerate(seg0to9):
        if int(cur,2)|int(seg,2) == int(seg,2):
            #cur이 i에 해당하는 stick에 포함되는 경우
            ck[i][j]=bit_count(int(cur,2)^int(seg,2))

dp=[[False]*(k+1) for _ in range(n+1)]
dp[n][0]=True
for i in range(n,0,-1):
    for j in range(k+1):
        if dp[i][j]:
            for d in range(10):
                if ck[i-1][d]!=-1 and ck[i-1][d]+j<=k:
                    dp[i-1][j+ck[i-1][d]]=True
if not dp[0][k]:
    print("-1")
    exit(0)
for i in range(n):
    cur=-1
    for d in range(9,-1,-1):
        if ck[i][d]!=-1 and ck[i][d]<=k and dp[i+1][k-ck[i][d]]:
            cur=d
            k-=ck[i][d]
            break
    print(cur,end="")