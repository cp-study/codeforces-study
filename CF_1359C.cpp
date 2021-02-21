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
#define ld long double
using namespace std;

ld temp(long double h, long double c, int o) {
    return ((o + 1) * h + c * o) / (2 * o + 1);
}
int main() {
    ll tc;
    cin >> tc;
    while (tc--) {
        ll h, c, t;
        int ans = 0;
        cin >> h >> c >> t;
        if (t <= (h + c) / 2) {
            ans = 2;
        }
        else {
            int lo = 0, hi = 1e9;
            while (lo <= hi)
            {
                int m = (lo + hi) / 2;
                ld tmp1 = temp(h, c, m);
                ld tmp2 = temp(h, c, m + 1);
                ld abs1 = abs(t - tmp1), abs2 = abs(t - tmp2);
                if (abs2 >= abs1)
                {
                    ans = 2 * m + 1;
                    hi = m - 1;
                }
                else lo = m + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;

}