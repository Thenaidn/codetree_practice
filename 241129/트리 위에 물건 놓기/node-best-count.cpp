#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
vector<int> tree[MAXN + 1];
int dp[MAXN + 1][2]; 
bool visited[MAXN + 1];

void dfs(int node) {
    visited[node] = true;

    // 초기값 설정
    dp[node][0] = 0;
    dp[node][1] = 1; // 물건을 놓는 경우

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child);

            dp[node][0] += dp[child][1];

        
            dp[node][1] += min(dp[child][0], dp[child][1]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    // 트리 입력
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}
