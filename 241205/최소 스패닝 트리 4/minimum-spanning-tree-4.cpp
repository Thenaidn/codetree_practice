#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005

int uf[MAXN], Size[MAXN]; char mode[MAXN];

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
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
    for (int i = 1; i <= n; i++) {
        char md; cin >> md;
        mode[i] = md;
        uf[i] = i;
        Size[i] = 1;
    }
    
    vector<pair<int, pair<int, int>>> v;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {b,a}});
    }

    sort(v.begin(), v.end(), cmp);

    int res = 0;
    int cnt = 0;
    int idx = 0;
    while (cnt < n - 1){
        if(mode[v[idx].second.first] != mode[v[idx].second.second] &&
            Find(v[idx].second.first) != Find(v[idx].second.second)){
            res += v[idx].first;
            Union(v[idx].second.first, v[idx].second.second);
            cnt++; 
        }
        idx++;
        if(idx >= v.size()){res = -1; break;}
    }

    cout << res;

    return 0;
}
