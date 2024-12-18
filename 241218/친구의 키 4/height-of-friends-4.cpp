#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAXN 100001

int n, m;
vector<int> edges[MAXN];
int indegree[MAXN]; // 진입 차수 저장
bool visited[MAXN]; // 사이클 검사용

bool detect_cycle(int current_edge_index, const vector<pair<int, int>>& relations) {
    // 진입 차수를 복원하기 위해 복사본 사용
    int temp_indegree[MAXN];
    memcpy(temp_indegree, indegree, sizeof(indegree));

    queue<int> q;

    // 초기 진입 차수가 0인 노드 큐에 추가
    for (int i = 1; i <= n; i++) {
        if (temp_indegree[i] == 0) {
            q.push(i);
        }
    }

    int visited_count = 0;

    // 위상 정렬 수행
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visited_count++;

        for (int next : edges[current]) {
            temp_indegree[next]--;
            if (temp_indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 사이클이 있는 경우, 방문한 노드 수가 전체 노드 수보다 적음
    return visited_count < n;
}

int main() {
    cin >> n >> m;

    vector<pair<int, int>> relations(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        relations[i] = {a, b};
    }

    // 간선을 하나씩 추가하며 사이클 검사
    for (int i = 0; i < m; i++) {
        int a = relations[i].first;
        int b = relations[i].second;

        // 간선 추가
        edges[a].push_back(b);
        indegree[b]++;

        // 사이클 여부 검사
        if (detect_cycle(i, relations)) {
            cout << i + 1 << endl; // 1-based index
            return 0;
        }
    }

    // 모든 간선을 추가했는데도 사이클이 없다면 일관성이 있음
    cout << "Consistent" << endl;
    return 0;
}
