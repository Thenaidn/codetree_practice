#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#define INF 1e9

using namespace std;

// 그래프와 거리 배열
vector<pair<int, int>> graph[1001];
vector<long long> dist;
int n, m;

void dijkstra(int start) {
    dist.assign(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        long long current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (current_dist > dist[current]) continue;

        for (auto edge : graph[current]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > dist[current] + weight) {
                dist[next] = dist[current] + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
        edges.push_back({x, y, z});
    }

    // 1. 기본 최단거리 계산
    dijkstra(1);
    long long base_distance = dist[n];

    long long max_increase = 0;

    // 2. 각 간선에 대해 길이를 2배로 늘린 경우 계산
    for (auto [x, y, z] : edges) {
        // 간선 길이 2배
        for (auto& edge : graph[x]) {
            if (edge.first == y && edge.second == z) edge.second = 2 * z;
        }
        for (auto& edge : graph[y]) {
            if (edge.first == x && edge.second == z) edge.second = 2 * z;
        }

        // 다시 최단거리 계산
        dijkstra(1);
        long long new_distance = dist[n];

        // 최단거리 변화량 계산
        if (new_distance != INF) {
            max_increase = max(max_increase, new_distance - base_distance);
        }

        // 간선 복구
        for (auto& edge : graph[x]) {
            if (edge.first == y && edge.second == 2 * z) edge.second = z;
        }
        for (auto& edge : graph[y]) {
            if (edge.first == x && edge.second == 2 * z) edge.second = z;
        }
    }

    // 3. 결과 출력
    cout << max_increase << endl;

    return 0;
}
