import sys
from collections import Counter
r=sys.stdin.readline
def gcd(a,b):
    while b:
        a,b=b,a%b
    return a
for _ in range(int(r())):
    counter=Counter()
    ans=0
    for _ in range(int(r())):
        x,y,u,v=map(int,r().split())
        x1,x2=u-x,v-y
        if x1==0:
            x2=x2//abs(x2)
        elif x2==0:
            x1=x1//abs(x1)
        else:
            g=abs(gcd(x1,x2))
            x1,x2=x1//g,x2//g
        counter[(x1,x2)]+=1
    for each in counter:
        target=(-each[0],-each[1])
        if target in counter:
            ans+=(counter[each]*counter[target])
    print(ans//2)

