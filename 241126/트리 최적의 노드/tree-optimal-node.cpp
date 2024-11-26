#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

struct Edge {
    int node, weight;
};

vector<Edge> adj[100001]; // 인접 리스트
int n; // 노드의 개수

map<int, int> points;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v;
        if (points.find(u) == points.end()) { points[u] = 1; }
        else { points[u]++; }
        if (points.find(v) == points.end()) { points[v] = 1; }
        else { points[v]++; }

        adj[u].push_back({ v, 1 });
        adj[v].push_back({ u, 1 });
    }

    int res = INT_MAX;
    for (pair<int, int> i : points) {
        res = min(res, bfs(i.first).second);
    }



    cout << res << "\n";

    return 0;
}
