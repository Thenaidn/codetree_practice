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
    
    int n, m, k; cin >> n >> m >> k;
    for(int i=1;i<=n;i++){uf[i] = i;}
    while(m--){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    int root_node;
    for(int i=0;i<k;i++){
        int a; cin >> a;
        if(i == 0){root_node = Find(a);}
        else if(Find(a) != root_node){
           cout << 0; return 0;
        }
    }
    cout << 1;
    return 0;
}