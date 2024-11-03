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

int arr[4][MAX_N];

string t;



int main() {
    int n, m;
    cin >> n >> m;

    set<int> s;
    int res = INT_MAX;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        set<int>::iterator it = s.lower_bound(num + m);
        if (it != s.end()) {
            res = min(res, *it - num);
        }

        it = s.lower_bound(num - m);
        if (it != s.begin()) {
            --it;
            if (num - *it >= m) {
                res = min(res, num - *it);
            }
        }


        s.insert(num);
    }

    if (res == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }

    return 0;
}