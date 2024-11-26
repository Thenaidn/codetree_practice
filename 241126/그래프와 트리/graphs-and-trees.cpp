#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;

pair<int, int> bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int node_count = 0;
    int edge_count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        node_count++;

        for (int neighbor : adj[node]) {
            edge_count++;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return {node_count, edge_count / 2};
}

int main() {
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int tree_count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            pair<int, int> tmp = bfs(i);
            int node_count = tmp.first; int edge_count = tmp.second;

            if (edge_count == node_count - 1) {
                tree_count++;
            }
        }
    }

    cout << tree_count;
    return 0;
}
