#include<bits/stdc++.h>
#define N 100000
#define ll long long
using namespace std;
int n,m;
vector<int> a[N+5];
inline ll check(ll u){
	ll ans = 0;
	int tot = a[0].size();//a[0]의 사이즈는 1번당의 현재 득표수
	vector<ll> nti;
	for(int i = 1;i<=N;++i){
		int j = 0,k = a[i].size();//j는 0부터 k는 i번째 당의 득표수를 의미함
		while(k>=u) ans += a[i][j++],--k,++tot;
		//k를 u까지 끌어내리면서 j는 증가시키고 i번당의 j번째 표를 사고 (코스트 증가)
		//득표수를 상승시킨다
		while(j<a[i].size()) nti.push_back(a[i][j++]);
		//j가 i번 당의 득표수를 따라 잡을때 까지 nti에 i번당의 j번 표값 즉 나머지 비싼 표를 집어넣는다
	}
	sort(nti.begin(),nti.end());
	//나머지 표들의 모음을 또 정렬하고
	for(int i = 0;i<nti.size();++i){
		if(tot>=u) break;
		//현 득표수가 목표득표수를 따라오면 종료
		ans += nti[i],++tot;
		//조건을 만족할때까지 cost를 증가시키면서 nti에서 표를 가져온다.
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i = 1;i<=n;++i){
		scanf("%d%d",&u,&v);//party와 cost입력 1번은 cost를 0으로 취급
		if(u == 1) v = 0;
		a[u].push_back(v);
	}
	for(int i = 1;i<=N;++i) sort(a[i].begin(),a[i].end());//모든 party에 대해 cost 오름차순 정렬
	ll l = 1,r = n;
	while(l<=r){//check 함수에대해 이분탐색을 수행 1~n범위내로 
		int mid = (l+r)/2;
		if(check(mid) < check(mid+1)) r = mid-1;
		else l = mid+1;
	}
	printf("%lld",check(l));
	return 0;
}