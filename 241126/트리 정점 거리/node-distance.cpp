#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct Edge {
    int node, weight;
};

vector<Edge> adj[100001]; // 인접 리스트
int n, m; // 노드의 개수
bool visited[10001] = { false, };
// 가장 먼 노드를 찾는 BFS
pair<int, int> bfs(int start) {
    vector<int> dist(n + 1, -1); // 거리를 -1로 초기화
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    int farthestNode = start; // 가장 먼 노드
    int maxDist = 0; // 최대 거리

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (const auto& edge : adj[current]) {
            int next = edge.node;
            int weight = edge.weight;

            if (dist[next] == -1) { // 방문하지 않은 노드
                dist[next] = dist[current] + weight;
                q.push(next);

                if (dist[next] > maxDist) {
                    maxDist = dist[next];
                    farthestNode = next;
                }
            }
        }
    }

    return { farthestNode, maxDist };
}

int dst = 0;
void dfs(int start, int end, int dist) {
    visited[start] = true;
    for (Edge i : adj[start]) {
        if (i.node == end) { dst = dist + i.weight; return; }
        else if(!visited[i.node]) { dfs(i.node, end, dist + i.weight); }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        dfs(a, b, 0);

        for (int i = 0; i < 10001; i++) { visited[i] = false; }
        cout << dst << endl; 
        dst = 0;
    }



    return 0;
}
