#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

set<int> painted;
int find(int dst) {
    int dest = dst;
    int minone = INT_MAX;
    while (dest > 1) {
        
        if (painted.find(dest) != painted.end()) { minone = min(minone, dest); }
        dest /= 2;
    }
    if (minone != INT_MAX) { return minone; }
    painted.insert(dst);
    return 0;
}

int main() {

    int n, q; cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        int res = find(a);

        cout << res << endl;
    }
    return 0;
}