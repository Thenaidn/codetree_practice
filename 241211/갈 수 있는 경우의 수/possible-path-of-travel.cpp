#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        in_degree[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) q.push(i);
    }

    dp[1] = 1; 

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
