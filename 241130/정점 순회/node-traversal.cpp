#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
vector<int> tree[MAXN + 1];
int dp[MAXN + 1];
bool visited[MAXN + 1];
int res = 0;
int n, s, d;
void dfs(int node) {
    visited[node] = true;


    dp[node] = 1;

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child);

            dp[node] = max(dp[child] + 1, dp[node]);

        }
    }
}
void dfs2(int node, int d, int& res) {
    visited[node] = true;
    bool needPaint = (dp[node] > d);

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs2(child, d, res);
            if (dp[child] > d) {
                needPaint = true;
            }
        }
    }

    
    if (needPaint && node != s) { 
        res += 2;
    }
}

int main() {

    cin >> n >> s >> d;

    // 트리 입력
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(s);


    fill(visited, visited + MAXN + 1, false); // 방문 배열 초기화
    int result = 0;
    dfs2(s, d, result);

    cout << result << endl;

    return 0;
}

