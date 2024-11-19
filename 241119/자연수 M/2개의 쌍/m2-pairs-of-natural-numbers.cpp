#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    set<int> s;
    int n; cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) { int a, b; cin >> a >> b; v[i] = { b,a }; }

    sort(v.begin(), v.end());
    int res = INT_MAX;

    while (v.size() > 0) {
        int a, b, c, d;
        a = v[0].first; b = v[0].second;
        c = v[v.size() - 1].first; d = v[v.size() - 1].second;
        res = min(res, a + c);
        b--;
        if (b == 0) {
            v.erase(v.begin());
        }
        if (a == c) { d = b; }
        d--;
        if (d == 0) {
            v.erase(v.begin() + v.size() - 1);
        }
    }

    cout << res;
    return 0;
}