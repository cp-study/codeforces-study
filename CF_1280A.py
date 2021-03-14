t = int(input())
mod = 10**9 + 7
for _ in range(t):
    x = int(input())
    s = input()
    i = 1
    while len(s) < x :
        s+=s[i:]*(ord(s[i-1])-49)
        i+=1
    l = len(s)
    while i <= x:
        l=(l+(l-i)*(ord(s[i-1])-49))%mod
        i+=1
    print(l)
