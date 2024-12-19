#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);  // 각 지층에서 압력을 가하는 지층들
    vector<int> inDegree(n + 1, 0);  // 각 지층의 진입 차수
    vector<int> pressure(n + 1, 1);  // 각 지층의 압력도 (기본값은 1)

    // 그래프 입력 받기
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;  // v로 가는 간선이 있으므로 v의 진입 차수 증가
    }

    // 위상 정렬을 위한 큐 (진입 차수가 0인 노드들)
    queue<int> q;

    // 진입 차수가 0인 노드를 큐에 넣기
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // 위상 정렬 수행하면서 압력도 계산
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 현재 노드가 다른 노드들에 압력을 미친다
        for (int next : graph[current]) {
            // 압력도 갱신 (가장 큰 압력도를 구한다)
            if (pressure[next] < pressure[current]) {
                pressure[next] = pressure[current];
            } else if (pressure[next] == pressure[current]) {
                pressure[next] = pressure[current] + 1;
            }

            // 진입 차수 감소
            inDegree[next]--;
            if (inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 압력도의 최대값 구하기
    int maxPressure = *max_element(pressure.begin() + 1, pressure.end());
    cout << maxPressure << endl;

    return 0;
}
