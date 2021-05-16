arr1 = [0]*26
arr2 = [[0]*26 for _ in range(26)]
s = input()
for i in range(len(s)):
    idx = ord(s[i]) - ord('a')
    for j in range(26):
        arr2[j][idx] += arr1[j]
    arr1[idx]+=1
ans = 0
for i in range(26):
    ans = max(ans,arr1[i])
for i in range(26):
    for j in range(26):
        ans = max(ans,arr2[i][j])
print(ans)
