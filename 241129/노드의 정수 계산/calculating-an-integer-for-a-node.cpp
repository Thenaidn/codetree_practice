#include <iostream>
#include <vector>
using namespace std;

const int n = 100008;  // 노드의 개수
vector<int> edges[n + 1]; // 트리를 저장할 인접 리스트
bool visited[n + 1];      // 방문 여부를 기록하는 배열
int parent[n + 1];        // 각 노드의 부모 노드를 기록하는 배열

// 노드에 주어진 고유 값
int start_points[n] = { -1, 1, 1, 1, 2, 2, 2, 4 };
int end_points[n] = { -1, 4, 7, 6, 6, 3, 5, 8 };
int arr[n + 1] = { 0, 0, 3, 3, 3, 4, 2, 6, 2 };

int dp[n + 1]; // dp[i]: i번 노드에 최종적으로 적히게 되는 값

// DFS를 통해 연결된 모든 정점을 순회합니다.
// 동시에 dp 값을 계산해줍니다.
void DFS(int x) {
    // 노드 x에 연결된 간선을 살펴보며 전부 방문해줍니다.
    for (int i = 0; i < (int)edges[x].size(); i++) {
        int y = edges[x][i];
        if (!visited[y]) {
            visited[y] = true;
            parent[y] = x;
            DFS(y);
        }
    }

    // 이제 되돌아가기 전에
    // 각각의 자식들을 다시 순회하며 dp[x] 값을 갱신합니다.
    dp[x] = arr[x];
    for (int i = 0; i < (int)edges[x].size(); i++) {
        int y = edges[x][i];
        if (parent[y] == x) {
            if (dp[y] > 0) { dp[x] += dp[y]; }

        }
    }
}

int main() {
    int n; cin >> n;
    // n - 1개의 간선 정보를 입력받습니다.
    for (int i = 2; i <= n; i++) {
        //int x = start_points[i];
        //int y = end_points[i];
        int t; int a;
        cin >> t >> arr[i] >> a;
        if (t == 0) { arr[i] *= -1; }

        // 간선 정보를 인접 리스트에 넣어줍니다.
        edges[i].push_back(a);
        edges[a].push_back(i);
    }

    // 1번 정점을 시작으로 DFS를 진행하며 값을 계산합니다.
    visited[1] = true;
    DFS(1);

    // 1번 노드에 적혀있는 값을 출력합니다.
    cout << dp[1];
    return 0;
}
