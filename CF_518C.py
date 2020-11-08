import sys
r=sys.stdin.readline
n,m,k=map(int,r().split())
screen=list(map(int,r().split()))
gesture=0
arr=[-1]*n              #인덱스 역참조 리스트
for i in range(n):
    screen[i]-=1        #인덱스로 바로접근하기위해 -1해주고
    arr[screen[i]]=i    #해당 값에대한 인덱스 리스트
for i in list(map(int,r().split())):
    i-=1                #i값도 동일하게 -1 처리
    pos = arr[i]        #현재 아이콘 값
    gesture+=pos//k+1   #k로 나눠 스크린값을 구하고 누르는 행동까지 추가
    if pos !=0:
        tmp=screen[pos-1]#전진 -> 값테이블과 역참조 인덱스 테이블 둘 다 갱신
        screen[pos-1],screen[pos]=screen[pos],screen[pos-1]
        arr[i],arr[tmp]=arr[tmp],arr[i]
print(gesture)
