import sys
r=sys.stdin.readline
def revAndnot(bit,idx):
    tmp=""
    for i in range(idx):
        tmp+='1' if bit[i]=='0' else '0'
    return tmp[::-1]+bit[idx:]
for _ in range(int(r())):
    n=int(r())  #length of binary
    a=r().strip()
    b=r().strip()
    ans=[]
    """ 3n operation method
    for i in range(n):
        if a[i]!=b[i]:
            if i>0:
                ans.append(str(i+1))
            ans.append('1')
            if i>0:
                ans.append(str(i+1))
    """
    """2n operation method
    for i in range(n-1,-1,-1):
        if b[i]==a[i]:
            continue
        elif a[0]==b[i]:#2op
            a=revAndnot(a,1)
            a=revAndnot(a,i+1)
            ans.append(str(1))
            ans.append(str(i+1))
        else:
            a=revAndnot(a,i+1)
            ans.append(str(i+1))
    """
    flip=False
    idx=0
    for i in range(n-1,-1,-1):
        if flip^(a[idx]==b[i]):
            ans.append(str(1))
        ans.append(str(i+1))
        if flip: idx-=i
        else: idx+=i
        flip^=True

    print(len(ans),end=" ")
    print(' '.join(ans))