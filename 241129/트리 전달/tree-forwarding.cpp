#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 100000;
vector<int> tree[MAXN + 1];
map<int, int> calc;
int dp[MAXN + 1] = { 0, };
bool visited[MAXN + 1];

void dfs(int node, int score) {
    visited[node] = true;

    if (calc.find(node) != calc.end()) {
        score += calc[node];
    }

    dp[node] += score;

    for (int child : tree[node]) {
        if (!visited[child]) {

            dfs(child, score);

            //dp[node] += dp[child];

        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 트리 입력
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (i == 1) { continue; }
        tree[a].push_back(i);
        tree[i].push_back(a);
    }

    //dfs(r);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        calc[a] += b;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    //cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}