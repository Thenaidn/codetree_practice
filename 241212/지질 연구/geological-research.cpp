#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int find_max_pressure_degree(int n, int m, vector<pair<int, int>>& edges) {
    // 그래프 초기화
    vector<vector<int>> adj(n + 1); // 인접 리스트
    vector<int> indegree(n + 1, 0);  // 각 노드의 indegree
    vector<int> pressure(n + 1, 1);  // 각 노드의 압력도, 초기값은 1
    
    // 그래프 간선 정보 처리
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);  // u에서 v로 가는 간선
        indegree[v]++;        // v로 들어오는 간선의 수 증가
    }
    
    // 위상 정렬을 위한 큐
    queue<int> q;
    
    // indegree가 0인 노드를 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    // 위상 정렬과 압력도 계산
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            // 압력도를 계산하는 부분
            int max_pressure_value = pressure[node];  // 압력을 받는 노드들의 압력도 중 가장 큰 값
            if (pressure[neighbor] < max_pressure_value) {
                pressure[neighbor] = max_pressure_value;
            } else if (pressure[neighbor] == max_pressure_value) {
                pressure[neighbor] = max_pressure_value + 1;
            }
            
            // 해당 노드의 indegree를 감소시킨 후, 0이면 큐에 넣기
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // 가장 큰 압력도 값 반환
    return *max_element(pressure.begin(), pressure.end());
}

int main() {
    int n, m;
    cin >> n >> m;  // 정점의 수 n, 간선의 수 m
    
    vector<pair<int, int>> edges(m);
    
    // 간선 입력
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    // 결과 출력
    cout << find_max_pressure_degree(n, m, edges) << endl;
    
    return 0;
}
