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

    vector<pair<int, int>> battle;

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        battle.push_back({ a, b });
    }

    for (auto i : battle) {
        if (i.first > i.second) {
            swap(i.second, i.first);
        }
    }

    sort(battle.begin(), battle.end(), cmp);

    for (auto i : battle) {
        if (red.size() == 0) {
            red.insert(i.first); 
            white.insert(i.second);
            continue;
        }
        int a = i.first; int b = i.second;
        if ((red.find(a) != red.end() && red.find(b) != red.end()) ||
            (white.find(a) != white.end() && white.find(b) != white.end())) {
            res = 0; break;
        }

        if (red.find(a) != red.end()) {
            white.insert(b);
        }
        else if (white.find(a) != white.end()) {
            red.insert(b);
        }
        else if (red.find(b) != red.end()) {
            white.insert(a);
        }
        else if (white.find(b) != white.end()) {
            red.insert(a);
        }
        
    }
    //int a, b, k; cin >> a >> b >> k;


    cout << res;
    return 0;
}
