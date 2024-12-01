#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

// 변수 선언:
int n;
vector<int> edges[MAX_N + 1];
bool visited[MAX_N + 1];
int parent[MAX_N + 1];

// dp[i][j][k] : i번 노드의 서브트리까지 고려했을 때
//               j = 0이면 아직 i번째 노드는 해결이 안된 상황
//               j = 1이면 i번째 노드까지 완벽히 해결된 상황
//               k = 0이면 i번째 노드에 물건을 놓지 않은 상황
//               k = 1이면 i번째 노드에 물건을 놓은 상황
//               이라 했을 때 놓아야 하는 최소 물건 개수
long long dp[MAX_N + 1][2][2];

// DFS를 통해 연결된 모든 정점을 순회합니다.
// 동시에 dp값을 계산해줍니다.
void DFS(int x) {
    // 노드 x에 연결된 간선을 살펴보며 전부 방문해줍니다.
    for(int i = 0; i < (int) edges[x].size(); i++) {
        int y = edges[x][i];
        if(!visited[y]) {
            visited[y] = true;
            parent[y] = x;
            DFS(y);
        }
    }

    // 이제 퇴각하기 전에
    // 각각의 자식들을 다시 순회하며 
    // dp[x]값을 갱신해줍니다.
    dp[x][0][0] = 0;
    dp[x][1][0] = 0;
    dp[x][1][1] = 1;

    for(int i = 0; i < (int) edges[x].size(); i++) {
        int y = edges[x][i];

        // y가 x의 자식이 아니라면 패스합니다.
        if(parent[y] != x)
            continue;

        // Case 1. 
        // (x, 0, 0) 상황이 되려면
        // 자식들은 해결이 끝났고, 각 위치에 물건을 놓은 적이 없는 상황이어야 합니다.
        dp[x][0][0] += dp[y][1][0];

        // Case 2.
        // (x, 1, 0) 상황이 되려면
        // 자식들은 전부 해결이 되었으면서 (j = 1)
        // 최소 (y, 1, 1)에 해당하는 자식이 하나 이상 있어야 합니다.
        // 우선 최솟값을 전부 더해줍니다.
        dp[x][1][0] += min(dp[y][1][1], dp[y][1][0]);

        // Case 3. 
        // (x, 1, 1) 상황이 되려면
        // 자식들의 j, k가 전혀 상관이 없습니다.
        dp[x][1][1] += min(min(dp[y][0][0], dp[y][1][0]), dp[y][1][1]);
    }

    // 불가능한 경우에는 
    // 불가능의 표시로 큰 값을 넣어줍니다.
    if(dp[x][1][0] == 0)
        dp[x][1][0] = (int)1e9;
    else {
        // 그렇지 않은 경우에는 
        // (x, 1, 0) case에 대해 
        // 최소 (y, 1, 1)에 해당하는 자식이 하나 이상 나오도록 하기 위해
        // 각각의 케이스 중 최적의 답을 계산해봅니다.
        long long best = (int)1e9;
        for(int i = 0; i < (int) edges[x].size(); i++) {
            int y = edges[x][i];

            // y가 x의 자식이 아니라면 패스합니다.
            if(parent[y] != x)
                continue;

            // y 노드에 대해 (y, 1, 1)를 선택했을 때의 경우를 계산해
            // 가능한 최솟값을 계산해줍니다. 
            best = min(best, dp[x][1][0] - min(dp[y][1][1], dp[y][1][0]) + dp[y][1][1]);
        }

        // (x, 1, 0) 값을 갱신해줍니다.
        dp[x][1][0] = best;
    }
}

int main() {
    // 입력:
    cin >> n;
    // n - 1개의 간선 정보를 입력받습니다.
    for(int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        
        // 간선 정보를 인접리스트에 넣어줍니다.
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // 1번 정점을 루트로 하는 트리를 만들어 문제를 해결합니다.
    // 1번 정점을 시작으로 DFS를 진행하며 dp값을 갱신합니다.
    visited[1] = true;
    DFS(1);

    // dp[1][1][0], dp[1][1][1] 중 최솟값을 출력합니다.
    cout << min(dp[1][1][0], dp[1][1][1]);
    return 0;
}