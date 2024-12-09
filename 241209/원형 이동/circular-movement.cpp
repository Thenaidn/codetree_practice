#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if( m <= 1){cout << 1; return 0;}
    // 중앙에서 각 구역까지의 비용
    vector<int> center_cost(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> center_cost[i];
    }

    // 간선 정보 초기화
    vector<vector<int>> graph(n + 1);

    // 원형 건물의 구간 연결 (원형이기 때문에 i와 i+1, n번과 1번도 연결)
    for (int i = 1; i <= n; i++) {
        int next = (i % n) + 1;
        graph[i].push_back(next);
        graph[next].push_back(i);
    }

    // 공사 구간 처리
    vector<vector<bool>> blocked(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        blocked[a][b] = true;
        blocked[b][a] = true;
    }

    // 우선순위 큐를 사용하여 프림 알고리즘 구현
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    // 중앙에서 1번 구역으로 이동할 때의 비용을 시작점으로 설정
    pq.push({center_cost[1], 1});
    dist[1] = center_cost[1];

    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        // 구역을 이동하며 최소 비용을 갱신
        for (int next : graph[current]) {
            if (!visited[next] && !blocked[current][next] && dist[next] > cost + center_cost[next]) {
                dist[next] = cost + center_cost[next];
                pq.push({dist[next], next});
            }
        }
    }

    // 모든 구역을 이동할 수 있는지 확인
    int total_cost = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << 0 << endl; // 한 구역이라도 못 갔다면 0 출력
            return 0;
        }
        total_cost += dist[i];
    }

    if (total_cost <= k) {
        cout << 1 << endl; // 비용 내에 모든 구역을 이동 가능하면 1 출력
    } else {
        cout << 0 << endl; // 아니면 0 출력
    }

    return 0;
}
