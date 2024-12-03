#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100005

int uf[MAXN], Size[MAXN];

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

    int res = 0;

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
        if(Find(a) == Find(b)){res++;}
        else{Union(a, b);}
    }

    for (int i = 1; i <= n; i++) {
        if(Size[i] > 0){res++;}
    }
    cout << res - 1;
    return 0;
}
