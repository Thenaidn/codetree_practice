#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 100000

using namespace std;

// 변수 선언:
int n;
vector<int> edge[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];
int max_dist;
int last_node;

// 모든 노드의 정점을 탐색하는 DFS를 진행합니다.
void DFS(int x) {
    visited[x] = true;

    for(int i = 0; i < edge[x].size(); i++) {
        int y = edge[x][i];

        // 이미 방문한 정점이면 스킵합니다.
        if(visited[y]) continue;

        dist[y] = dist[x] + 1;

        // 현재 정점을 기준으로 가장 먼 노드를 찾습니다.
        if(dist[y] > max_dist) {
            max_dist = dist[y];
            last_node = y;
        }

        DFS(y);
    }
}

int main() {
    // 입력:
    cin >> n;

    // n - 1개의 간선 정보를 입력받습니다.
    for(int i = 1; i <= n - 1; i++) {
        int x, y;

        cin >> x >> y;

        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    // DFS를 통해 가장 먼 노드를 찾습니다.
    DFS(1);

    // 가장 먼 노드에서 시작해 다시 한번 DFS를 돌려 트리의 가장 긴 거리를 찾습니다.
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }

    DFS(last_node);

    // 거리의 중간값을 출력합니다.
    cout << (max_dist + 1) / 2;
    return 0;
}