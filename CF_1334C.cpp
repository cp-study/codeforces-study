#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;

int n;
long long a[300000];
long long b[300000];

long long solve() {
	long long sum = 0;

	// 폭발로 깎이는 대미지
	for (int i = 0; i < n; i++)
	{
		sum += max(0LL, a[i] - b[(i + n - 1) % n]);
	}

	long long minim = LLONG_MAX;
	// 직접 쏘는 대미지
	for (int i = 0; i < n; i++)
	{
		minim = min(minim, a[i] - max(0LL, a[i] - b[(i + n - 1) % n]));
	}

	return sum + minim;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d", &n);


		for (int i = 0; i < n; i++)
		{
			scanf("%lld %lld", a + i, b + i);
		}

		printf("%lld\n", solve());
	}
}
