n, m, d = map(int, input().split())
a = list(map(int, input().split()))
a = sorted([(a[i],i) for i in range(n)])
coffeeTable = [0] * n
minimumDays = 0
i = j = 0
while i<n:
	if a[i][0] - d <= a[j][0] :
		minimumDays += 1
		coffeeTable[a[i][1]] = minimumDays
	else:
		coffeeTable[a[i][1]] = coffeeTable[a[j][1]]
		j += 1
	i += 1
print(minimumDays)
print(' '.join(list(map(str, coffeeTable))))
