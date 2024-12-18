#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define MAXN 100001

int n, m1, m2;
vector<int> edges[MAXN];
int indegree[MAXN] = {0}; // 진입 차수 저장

bool can_direct_graph() {
    queue<int> q;
    int visited_count = 0;

    // 초기 진입 차수가 0인 노드를 큐에 추가
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 위상 정렬
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visited_count++;

        for (int next : edges[current]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 방문한 노드 수가 전체 노드 수와 같으면 사이클이 없음
    return visited_count == n;
}

int main() {
    cin >> n >> m1 >> m2;

    // 단방향 간선 추가
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++;
    }

    // 양방향 간선 처리
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;

        // 양방향 간선을 단방향 간선으로 설정 (a->b)
        edges[a].push_back(b);
        indegree[b]++;
    }

    // 사이클이 없는지 판단
    if (can_direct_graph()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
