from math import gcd
 
n = int(input())
ans = []
check = []
prod = 1
for i in range(1, n):
       if (gcd(n, i) == 1):
              prod = prod*i%n
              check.append(prod)
              ans.append(i)
while True:
    if check[-1] != 1:
        ans.pop()
        check.pop()
    else:
        break
print(len(ans))
print(*ans)
