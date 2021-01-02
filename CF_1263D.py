n = int(input())
arr = set()
for _ in range(n):
    arr.add(''.join(set(input())))
arr = list(arr)
cnt = 0
for i in range(len(arr)):
    for j in range(len(arr)):
        if i != j:
            if len(set(arr[i]).intersection(set(arr[j]))) > 0:
                cnt += 1
                break
if cnt == 0:
    print(len(arr) - cnt)
else:
    print(len(arr) - cnt + 1)
