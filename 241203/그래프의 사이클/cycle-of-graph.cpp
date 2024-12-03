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
        uf[i] = i;
        Size[i] = 1;
    }

    for (int i=1;i<=m;i++) {
        
        int a, b;
        cin >> a >> b;
        if(Find(a) == Find(b)){ cout << i; return 0;}
        Union(a, b);
        
        
    }
    cout << "happy";
    return 0;
}
