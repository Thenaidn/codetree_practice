#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 100005

int uf[MAXN], Size[MAXN];

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
}

bool cmp(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b){
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
    vector<pair<int, pair<int, int>>> points;
    for (int i = 1; i <= n; i++) {
        uf[i] = i;
        int a, b; cin >> a >> b;
        points.push_back({i, {a, b}});
    }

    vector<pair<double, pair<int, int>>> v;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j){continue;}
            int distance = dist(points[i].second.first, points[i].second.second, 
            points[j].second.first, points[j].second.second);
            v.push_back({distance, {points[i].first, points[j].first}});
        }
    }
    
    sort(v.begin(), v.end(), cmp);


    for (int i=0;i<m;i++) {
        int a, b; Union(a, b);
    }

    

    double res = 0;
    int cnt = 0;
    int idx = 0;
    while (cnt < n - 1 - m){
        if(Find(v[idx].second.first) != Find(v[idx].second.second)){
            res += v[idx].first;
            Union(v[idx].second.first, v[idx].second.second);
            cnt++; 
        }
        idx++;
    }

    printf("%.2lf", res);

    return 0;
}
