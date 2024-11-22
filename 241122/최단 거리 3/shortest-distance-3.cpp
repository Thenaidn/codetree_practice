#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define INF (int)1e9

using namespace std;

// 변수 선언
vector<pair<int, int>> graph[1001];
int dist[1001];

int main() {
    int n, m;
    cin >> n >> m;

    // 그래프를 인접 리스트로 표현
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z}); // 양방향
    }

    int a, b;
    cin >> a >> b;

    // 초기화
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    // 다익스트라 알고리즘
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[a] = 0;
    pq.push({0, a}); // (거리, 정점)

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        // 더 짧은 경로가 이미 있다면 무시
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

    // 결과 출력
    cout << dist[b] << endl;

    return 0;
}
