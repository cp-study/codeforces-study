import sys,math
r=sys.stdin.readline
n,m=map(int,r().split())
MOD = 998244353
fact=[1]*(2*(10**5)+1)
def nCr(n, r):
    return div(fact[n],mul(fact[r],fact[n-r]))

def mul(x,y):
    return x*y%MOD

def div(x,y):
    return mul(x,inv(y))

def inv(x):
    return pow(x,MOD-2,MOD)

for i in range(1,2*10**5+1):
    fact[i]=mul(fact[i-1],i)

ans=0
if n>2:
    ans=mul(nCr(m,n-1),mul(n-2,pow(2,n-3,MOD)))
print(ans)

