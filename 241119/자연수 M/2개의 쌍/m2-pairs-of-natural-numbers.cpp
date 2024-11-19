#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    set<int> s;
    int n; cin >> n;
    vector<pair<long long, long long>> v(n);

    for (int i = 0; i < n; i++) { long long a, b; cin >> a >> b; v[i] = { b,a }; }

    sort(v.begin(), v.end());
    long long res = 0;

    while (v.size() > 0) {
        long long a, b, c, d;
        a = v[0].first; b = v[0].second;
        c = v[v.size() - 1].first; d = v[v.size() - 1].second;
        res = max(res, a + c);
        long long tmp = min(b, d);
        v[0].second -= tmp;
        if (v[0].second == 0) {
            v.erase(v.begin());
        }
        if (v.size() >= 1) {
            v[v.size() - 1].second -= tmp;
            if (v[v.size() - 1].second == 0) {
                v.erase(v.begin() + v.size() - 1);
            }
        }
        
    }

    cout << res;
    return 0;
}