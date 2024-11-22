#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

#define INF (int)1e9

using namespace std;

// 변수 선언
vector<pair<int, int>> graph[100001];
vector<int> dist_from_a, dist_from_b, dist_from_c;

void dijkstra(int start, vector<int>& dist, int n) {
    dist.assign(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({ 0, start }); // (거리, 정점)

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (current_dist > dist[current]) continue;

        for (auto edge : graph[current]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > dist[current] + weight) {
                dist[next] = dist[current] + weight;
                pq.push({ dist[next], next });
            }
        }
    }
}
char grid[30][30];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main() {
    int n, a, b;
    cin >> n >> a >> b;

    // 그래프 입력
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k]; int nx = j + dx[k];
                if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                    if (grid[i][j] == grid[ny][nx]) {
                        graph[i * n + j + 1].push_back({ ny * n + nx + 1, a });
                        graph[ny * n + nx + 1].push_back({ i * n + j + 1, a });
                    }
                    else {
                        graph[i * n + j + 1].push_back({ ny * n + nx + 1, b });
                        graph[ny * n + nx + 1].push_back({ i * n + j + 1, b });
                    }
                }
            }
        }
    }
    int max_distance = 0;
    for (int k = 1; k <= n * n; k++) {
        dijkstra(k, dist_from_a, n * n);
        for (int i = 1; i <= n * n; i++) {
            max_distance = max(max_distance, dist_from_a[i]);

        }
    }
    // 다익스트라 실행
    //dijkstra(1, dist_from_a, n * n);
    //dijkstra(3, dist_from_b, n * n);

    //// 각 정점에서 a, b, c 중 가장 가까운 거리의 최대값 계산
    //
    //for (int i = 1; i <= n * n; i++) {
    //    max_distance = max(max_distance, max(dist_from_a[i], dist_from_b[i]));

    //}

    // 결과 출력
    cout << max_distance << endl;

    return 0;
}
