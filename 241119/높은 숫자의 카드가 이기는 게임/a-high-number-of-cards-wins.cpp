#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    set<int> s;
    int n; cin >> n;
    for (int i = 1; i <= n * 2; i++) { s.insert(i); }
    // 여기에 코드를 작성해주세요.
    vector<int> s2;
    for (int i = 0; i < n; i++) { int a; cin >> a; s.erase(a); s2.push_back(a); }

    int res = 0;
    for (int i : s2) {
        auto it = s.upper_bound(i);

        if (it != s.end()) {
            res++; s.erase(*it);
        }
    }

    cout << res;
    return 0;
}