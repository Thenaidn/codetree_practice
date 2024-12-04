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


    for (int i = 2; i <= m; i++) {
        int a, b; cin >> a >> b;
        a = Find(a); b = Find(b);
        if (a == b) { res = 0; break; }
        else if (a == Find(r1)) {
            Union(b, w1);
        }
        else if (a == Find(w1)) {
            Union(b, r1);
        }
        else if (b == Find(r1)) {
            Union(a, w1);
        }
        else if (b == Find(w1)) {
            Union(a, r1);
        }
        else {
            Union(a, r1); Union(b, w1);
        }
        //Union(i, a);
    }

    //int a, b, k; cin >> a >> b >> k;


    cout << res;
    return 0;
}
