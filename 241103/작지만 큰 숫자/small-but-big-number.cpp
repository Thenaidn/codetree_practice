#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;

#define MAX_N 100001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;


string t;



int main() {

    cin >> n >> m;
    set<long long> s;
    long long a, b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }

    for (int i = 0; i < m; i++) {
        cin >> b;
        auto it = s.upper_bound(b);
        it--;
        if (it != s.end()) {
            cout << *it << endl;
            s.erase(*it);
        }
        else {
            cout << -1 << endl;
        }
    }
}