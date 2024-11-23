#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

#define INF (int)1e9

using namespace std;
long long dist_between_red;
// 변수 선언
vector<pair<int, int>> graph[100001];
vector<long long> dist_from_a, dist_from_b, dist_from_c;

void dijkstra(int start, vector<long long>& dist, int n) {
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

int main() {
    int n, m;
    cin >> n >> m;

    int a, b, c;
    cin >> a >> b;

    // 그래프 입력
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({ y, z });
        graph[y].push_back({ x, z }); // 양방향
    }

    

    // 다익스트라 실행
    dijkstra(a, dist_from_a, n);
    dist_between_red = dist_from_a[b];
    dijkstra(b, dist_from_b, n);

    // 각 정점에서 a, b, c 중 가장 가까운 거리의 최대값 계산
    long long max_closest_distance = INF;
    for (int i = 1; i <= n; i++) {
        if(i==a||i==b){continue;}

        

        long long closest_distance = min((dist_from_a[i] + dist_from_b[i])*2, 
        dist_from_a[i] + dist_from_b[i] + dist_between_red);

        if (closest_distance < INF) {
            max_closest_distance = min(max_closest_distance, closest_distance);
        }

    }
    if(max_closest_distance == INF){cout << -1;}
    // 결과 출력
    else{cout << max_closest_distance << endl;}

    return 0;
}
