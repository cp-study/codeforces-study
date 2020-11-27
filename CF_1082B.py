n = int(input())
s = str(input())
start = 0
end = 0
ans = 0
for i in range(len(s)):
    if s[i] == 'G':
        start += 1
    elif s[i] == 'S':
        start,end = 0,start
    ans = max(ans,start+end+1)
print(min(ans,s.count("G")))
