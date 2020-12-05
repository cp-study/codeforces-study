n = int(input())
t = [int(v) for v in input().split()]
ans = [0 for _ in range(n)]

for i in range(n):
	num = [0 for _ in range(n+1)]
	most_num = 0 
	for j in range(i, n):
		num[t[j]] += 1
		if num[t[j]] > num[most_num] or (num[t[j]] == num[most_num] and t[j] < most_num):
			most_num = t[j]
		ans[most_num-1] += 1
for i in ans:
	print(i,end=' ')
