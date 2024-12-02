#include <iostream>
#include <unordered_set>
using namespace std;

#define MAXN 100005

int uf[MAXN];
unordered_set<int> root[MAXN];

int Find(int x) {
    if (uf[x] == x) { return x; }
    int root_node = Find(uf[x]);
    root[x].erase(x);
    root[root_node].insert(x);
    uf[x] = root_node;
    return root_node;
}

void Union(int x, int y) {
    int x1 = Find(x); int y1 = Find(y);
    root[x1].erase(x1);
    root[y1].insert(x1);
    uf[x1] = y1;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) { uf[i] = i; root[i].insert(i); }

    while (m--) {
        char q; int a, b;
        cin >> q;
        if (q == 'x') {
            cin >> a >> b;
            if (uf[a] != uf[b]) {
                Union(a, b);
            }
        }
        else {
            cin >> a;
            cout << root[Find(uf[a])].size() << endl;
        }
    }
    return 0;
}