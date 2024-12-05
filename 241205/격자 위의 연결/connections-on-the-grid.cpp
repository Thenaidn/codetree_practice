#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005

int uf[MAXN], Size[MAXN];

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first < b.first;
}

int Find(int x) {
    if (x == uf[x]) return x;
    return uf[x] = Find(uf[x]);
}

void Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX != rootY) {
        if (Size[rootX] < Size[rootY]) {
            swap(rootX, rootY);
        }
        uf[rootY] = rootX;
        Size[rootX] += Size[rootY];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        uf[i] = i;
        Size[i] = 1;
    }

    vector<pair<int, pair<int, int>>> v;

    int a, b, c;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            cin >> a;
            v.push_back({ a, {m * i + j, m * i + j + 1} });
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a;
            v.push_back({ a, {m * i + j, m * (i + 1) + j} });
        }
    }


    sort(v.begin(), v.end(), cmp);

    int res = 0;
    int cnt = 0;
    int idx = 0;
    while (cnt < n * m - 1) {
        if (Find(v[idx].second.first) != Find(v[idx].second.second)) {
            res += v[idx].first;
            Union(v[idx].second.first, v[idx].second.second);
            cnt++;
        }
        idx++;
    }

    cout << res;

    return 0;
}
