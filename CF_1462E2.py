import sys
from bisect import bisect_right
r=sys.stdin.readline
MOD=10**9+7
N=200001
fact=[1]
for i in range(1,N+1):
    fact.append((fact[-1]*i)%MOD)
def nCr(n,r):
    if n<=r:
        return n==r
    a=fact[n]
    b=(fact[n-r]*fact[r])%MOD
    b=pow(b,MOD-2,MOD)
    return (a*b)%MOD
for _ in range(int(r())):
    n,m,k=map(int,r().split())
    seq=list(map(int,r().split()))
    seq.sort()
    ans=0
    for i in range(n-m+1):
        j=bisect_right(seq,seq[i]+k,lo=i+1)
        idx=j-i-1
        ans+=nCr(idx,m-1)
        ans%=MOD
    print(ans)
