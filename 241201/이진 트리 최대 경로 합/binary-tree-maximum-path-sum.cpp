#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
vector<int> tree[MAXN + 1];
int dp[MAXN + 1];
bool visited[MAXN + 1];

int res = 0;
int m;

void dfs(int node, int s) {
    visited[node] = true;

    s += dp[node];
    if(res < s){
        m = node;
        res = s;
    }
    
    

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child, s);
        }
    }
}

int main() {
    int n, r, q;
    cin >> n;

    // 트리 입력
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        cin >> dp[i];
    }
    dfs(1, 0);
    res = 0;
    for(int i=0;i<=100000;i++){visited[i] = false;}
    dfs(m, 0);


    cout << res;

    

    //cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}
