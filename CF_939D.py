n=int(input())
s=input()
t=input()
parent=[i for i in range(27)]
ans=0
res=[]

def find(target):
    if parent[target] == target:
        return target
    
    parent[target] = find(parent[target])
    return parent[target]

def union(a, b):
    a = find(a)
    b = find(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b    

for j in range(n):
    a,b=ord(s[j])-97,ord(t[j])-97
    if find(a)!=find(b):
        res.append([s[j],t[j]])
        ans+=1
        union(a,b)
        
print(ans)
for j in res:
    print(*j)
