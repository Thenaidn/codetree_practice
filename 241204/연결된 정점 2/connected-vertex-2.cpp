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
    cin >> n;
    for (int i = 1; i <= 100000; i++) {
        uf[i] = i;
        Size[i] = 1;
    }
    m = n;

    while (m--) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
        cout << Size[Find(a)] << endl;
    }

    return 0;
}
