#include <iostream>
using namespace std;

#define MAXN 100001

int uf[MAXN];

int Find(int x){
    if(uf[x] == x){return x;}
    int root_node = Find(uf[x]);
    uf[x] = root_node;
    return root_node;
}

void Union(int x, int y){
    int x1 = Find(x); int y1 = Find(y);
    uf[x1] = y1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++){uf[i] = i;}
    while(m--){
        int q, a, b;
        cin >> q >> a >> b;
        if(q == 0){
            if(uf[a] != uf[b]){
                Union(a,b);
            }
        }
        else{
            if(Find(uf[a]) == Find(uf[b])){cout << 1 << endl;}
            else{cout << 0 << endl;}
        }
    }
    return 0;
}