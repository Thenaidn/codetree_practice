#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <set>

using namespace std;

int a, b, c, d, e, n, m, k;
string t, t2;

set<int> s[26];
set<int> s2[26];
set<int> exclude;

bool IsPossible() {
    for (int i = 0; i < 26; i++) {
        s2[i] = s[i];
        for (int j : exclude) {
            if (s2[i].find(j) != s2[i].end()) {
                s2[i].erase(j);
            }
        }
    }

    int prev = -1;
    for (int i = 0; i < t2.length(); i++) {
        if (s2[t2[i] - 'a'].empty()) { 
            return false;
        }

        auto it = s2[t2[i] - 'a'].begin();
        if (it != s2[t2[i] - 'a'].end()) {
            int latest = *it;
            if (latest < prev) {
                while (!s2[t2[i] - 'a'].empty()) {
                    s2[t2[i] - 'a'].erase(latest);
                    it = s2[t2[i] - 'a'].begin();
                    if (it != s2[t2[i] - 'a'].end()) {
                        latest = *it;
                    }
                    if (latest >= prev) { break; }
                }
                if (latest < prev) { return false; }
            }
            prev = latest;
            s2[t2[i] - 'a'].erase(latest);
        }
    }

    return true;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t >> t2;

    for (int i = 0; i < t.length(); i++) {
        s[t[i] - 'a'].insert(i);
    }

    int res = 0;
    for (int i = 0; i < t.length(); i++) {
        if (IsPossible()) { res++; }
        cin >> a;
        exclude.insert(a - 1);
    }
    if (IsPossible()) { res++; }

    cout << res;

    return 0;
}
