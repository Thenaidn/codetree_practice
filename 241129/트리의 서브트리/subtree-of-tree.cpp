#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
vector<int> tree[MAXN + 1];
int dp[MAXN + 1];
bool visited[MAXN + 1];

void dfs(int node) {
    visited[node] = true;


    dp[node] = 1;

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child);

            dp[node] += dp[child];

        }
    }
}

int main() {
    int n, r, q;
    cin >> n >> r >> q;

    // 트리 입력
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(r);

    for (int i = 0; i < q; i++) {
        int u; cin >> u;
        cout << dp[u] << endl;
    }

    //cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}
