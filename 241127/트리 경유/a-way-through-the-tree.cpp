#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

set<int> painted;
int find(int dst) {
    int dest = dst;
    int minone = 0;
    while (dest > 1) {

        if (painted.find(dest) != painted.end()) { minone = dest; }
        dest /= 2;
    }
    if (minone == 0) { painted.insert(dst); }
    return minone;
}

int main() {

    int n, q; cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        cout << find(a) << endl;
    }
    return 0;
}