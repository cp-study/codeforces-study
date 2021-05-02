from math import gcd
 
n = int(input())
ans = []
prod = 1
for i in range(1, n):
       if (gcd(n, i) == 1):
              prod = prod*i%n
              ans.append(i)
if prod != 1:
       ans.pop()
print(len(ans))
print(*ans)
