#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define MAXN 100005

int uf[MAXN], Size[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int Find(int x) {
    if (x == uf[x]) return x;
    return uf[x] = Find(uf[x]);
}

void Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX != rootY) {
        if (rootX > rootY) {
            swap(rootX, rootY);
        }
        uf[rootY] = rootX;
        Size[rootX] += Size[rootY];
        Size[rootY] = 0;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int res = 1;

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        uf[i] = i;
        Size[i] = 1;
    }
    //m = n - 2;

    unordered_set<int> red; 
    unordered_set<int> white;

    int r1, w1; cin >> r1 >> w1;
    red.insert(r1); white.insert(w1);
    for (int i = 2; i <= m; i++) {
        int a, b; cin >> a >> b;
        if (Find(a) == Find(b)) { res = 0; break; }
        if (red.find(a) != red.end()) {
            Union(b, w1);
            white.insert(b);
        }
        if (white.find(a) != white.end()) {
            Union(b, r1);
            red.insert(b);
        }
        if (red.find(b) != red.end()) {
            Union(a, w1);
            white.insert(a);
        }
        if (white.find(b) != white.end()) {
            Union(a, r1);
            red.insert(a);
        }
        //Union(i, a);
    }

    //int a, b, k; cin >> a >> b >> k;


    cout << res;
    return 0;
}
