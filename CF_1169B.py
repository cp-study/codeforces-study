n,m = (((map(int, input().split()))))
arr = []
for i in range(m):
    a,b = (((map(int, input().split()))))
    arr.append([a,b])
 
flag = False
x = arr[0][0]
brr = []
for pair in arr:
    if x not in pair:
        brr.append(pair)
if len(brr) == 0:
    print("YES")
    exit()
Dict = {}
for pair in brr:
    if pair[0] not in Dict:
        Dict[pair[0]] = 1
    else:
        Dict[pair[0]] +=1
    if pair[1] not in Dict:
        Dict[pair[1]] = 1
    else:
        Dict[pair[1]] +=1
for i in Dict:
    if Dict[i] == len(brr):
        flag = True
        break
if flag:
    print("YES")
    exit()

x = arr[0][1]
brr = []
for pair in arr:
    if x not in pair:
        brr.append(pair)
if len(brr) == 0:
    print("YES")
    exit()
Dict = {}
for pair in brr:
    if pair[0] not in Dict:
        Dict[pair[0]] = 1
    else:
        Dict[pair[0]] +=1
    if pair[1] not in Dict:
        Dict[pair[1]] = 1
    else:
        Dict[pair[1]] +=1
for i in Dict:
    if Dict[i] == len(brr):
        flag = True
        break
if flag:
    print("YES")
else:
    print("NO")
