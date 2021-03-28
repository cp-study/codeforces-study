n,m = map(int,input().split())
s = input()
t = input()

start = 1000000 * [0]
end = 1000000 * [0]
j = 0

for i in range(n):
	if j == m:
		break
	if t[j] == s[i]:
		start[j] = i
		j += 1

j = m - 1
for i in range(n - 1, -1, -1):
	if j == -1:
		break
	if t[j] == s[i]:
		end[j] = i
		j -= 1

ans = -1
for i in range(1, m):
	ans = max(ans, abs(end[i] - start[i - 1]))

print(ans)
