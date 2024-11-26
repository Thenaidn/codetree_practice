#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct Edge {
    int node, weight;
};
int b;
vector<int> adj[100001]; // 인접 리스트
bool visited[10000] = { false, };
int n; // 노드의 개수

int res = 0;
// 가장 먼 노드를 찾는 BFS
void dfs(int start) {
    if (start == b) { return; }
    res++;
    visited[start] = true;
    for (int i : adj[start]) {
        dfs(i);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int start = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == -1) { start = i; }
        else { adj[a].push_back(i); }
    }
    cin >> b;
    adj[b].clear();

    dfs(start);

    cout << res - 1 << "\n";

    return 0;
}
