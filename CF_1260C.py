import sys
read=sys.stdin.readline
def gcd(a,b):
    tmp=a%b
    while tmp:
        a=b
        b=tmp
        tmp=a%b
    return abs(b)
for _ in range(int(read())):
    r,b,k=map(int,read().split())
    a,b=min(r,b),max(r,b)
    g=gcd(a,b)
    a/=g
    b/=g
    if (k-1)*a+1<b:
        print("REBEL")
    else:
        print("OBEY")                
