#include <iostream>
#include <vector>
#include <algorithm>
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

    //int res = 0;

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        uf[i] = i;
        Size[i] = 1;
    }
    //m = n - 2;

    while (m--) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    int a, b, k; cin >> a >> b >> k;

    int res = Size[Find(a)];

    vector<pair<int, int>> sizes;
    //sizes.push_back({ -1, -1 });
    for (int i = 1; i <= n; i++) {
        sizes.push_back({ Size[i], i });
    }
    sort(sizes.begin(), sizes.end(), cmp);


    for (int i = 0; i < sizes.size(); i++) {
        if (Find(sizes[i].second) == Find(a) || 
        Find(b) == Find(sizes[i].second)) { continue; }
        res += sizes[i].first;
        k--;
        if (k <= 0) {break;}
    }
   
    cout << res;
    return 0;
}
