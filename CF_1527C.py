t = int(input())
for j in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    
    value = {}
    fa, ca = 0, 0
    
    for i in range(n):
      if a[i] in value:
        ca += value[a[i]]
      else:
        value[a[i]]=0
      value[a[i]] += i+1
      fa += ca
    
    print(fa)
