def primeFactors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

for _ in range(int(input())):
    p, q = list(map(int, input().split()))
    qFactors = primeFactors(q)
    possible = []
    for num in qFactors:
        temp = p
        while temp%q==0:
            temp//=num
        possible.append(temp)
    print(max(possible))
