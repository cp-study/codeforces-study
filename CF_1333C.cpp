#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <functional>
#include <cstdlib>
#include <list>
#include <iomanip>
#define ll long long
using namespace std;

int main() {
    int n; 
    
    cin >> n;
    vector<ll> prefix(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        prefix[i + 1] = prefix[i] + num;
    }

    int begin = 1, end = 0;
    long long ans = 0;
    set<long long> s = { 0 };
    while (begin < n) {
        while (end < n && !s.count(prefix[end + 1])) {
            end++;
            s.insert(prefix[end]);
        }
        ans += end - begin;
        s.erase(prefix[begin]);

        begin++;
    }
    cout << ans << endl;
}