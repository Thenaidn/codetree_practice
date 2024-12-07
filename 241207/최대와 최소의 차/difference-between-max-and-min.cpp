#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 100005

int uf[MAXN], Size[MAXN]; int n, m;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.first < b.first;
}
bool cmp2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
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
        if (Size[rootX] < Size[rootY]) {
            swap(rootX, rootY);
        }
        uf[rootY] = rootX;
        Size[rootX] += Size[rootY];
    }
}

int kruskal(vector<pair<int, pair<int, int>>> v, int mode){
    if(mode == 1){
        sort(v.begin(), v.end(), cmp2);
    }
    else{
        sort(v.begin(), v.end(), cmp);
    }
    int res = 0;
    int cnt = 0;
    int idx = 0;
    while (cnt < n - 1){
        if(Find(v[idx].second.first) != Find(v[idx].second.second)){
            res += v[idx].first;
            Union(v[idx].second.first, v[idx].second.second);
            cnt++; 
        }
        idx++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        uf[i] = i;
        Size[i] = 1;
    }
    
    vector<pair<int, pair<int, int>>> v;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c==0){c=1;}
        else{c=0;}
        v.push_back({c, {b,a}});
    }

    

    int mi = pow(kruskal(v, 0), 2);

    for (int i = 1; i <= n; i++) {
        uf[i] = i;
        Size[i] = 1;
    }

    int ma = pow(kruskal(v, 1), 2);



    cout << ma - mi;

    return 0;
}
