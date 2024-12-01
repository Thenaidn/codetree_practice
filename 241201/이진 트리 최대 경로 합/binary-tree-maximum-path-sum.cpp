#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 30000

using namespace std;

// 변수 선언:
int n;
vector<int> edges[MAX_N + 1];
bool visited[MAX_N + 1];
int a[MAX_N + 1];
int dp[MAX_N + 1];
int max_length[MAX_N + 1];
int ans;

// 1번 노드를 시작으로 DFS를 진행하며 값을 갱신합니다.
// dp[i] = i번 노드를 루트로 하는 서브트리에서 
// i번 노드를 끝으로 하는 경로 중 최대 합에 해당하는 경로
// max_length[i] = i번 노드를 루트로 하는 서브트리에서
// 두 자식노드로 이어지는 경로의 최댓갑
void DFS(int x) {
    // 이진트리므로 최대 자식 개수는 2개입니다.
    // 자식의 번호를 관리합니다.
    vector<int> children;

    // 노드 x에 연결된 간선을 살펴보며 전부 방문해줍니다.
    for(int i = 0; i < (int) edges[x].size(); i++) {
        int y = edges[x][i];

        // 이미 방문한 정점이라면 스킵해줍니다.
        if(visited[y]) continue;

        visited[y] = true;
        DFS(y);

        // y번 노드의 경로의 길이를 path에 추가해줍니다.
        children.push_back(y);
    }

    // 왼쪽, 오른쪽 자식 번호를 기입해줍니다.
    // 만약 없다면 index가 0이 되도록 하여 후보 계산이 dp[0] = 0값을 이용하여
    // 답에 영향을 주지 않도록 합니다.
    int left = children.size() > 0 ? children[0] : 0;
    int right = children.size() > 1 ? children[1] : 0;

    // dp와 max_length를 갱신합니다.
    // dp의 경우 왼쪽 오른쪽 자식 중 값이 더 큰 경우에 현재 노드에 적혀있는 값을 추가합니다.
    // 단, 그 값이 음수라면 연결하지 않는 상태를 의미하는 0이 더 좋습니다.
    dp[x] = a[x] + max(0, max(dp[left], dp[right]));
    
    // max_length의 경우 현재 노드 + 왼쪽에서 얻을 수 있는 최대 + 오른쪽에서 얻을 수 있는 최대가 됩니다.
    max_length[x] = a[x] + max(0, dp[left]) + max(0, dp[right]);
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

    // n개의 노드에 적힌 값을 입력받습니다.
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    // 1번 노드를 시작으로 DFS를 진행하며 값을 갱신합니다.
    visited[1] = true;
    DFS(1);

    // 모든 max_length의 값 중 최댓값을 출력합니다.
    for(int i = 1; i <= n; i++)
        ans = max(ans, max_length[i]);

    cout << ans;
    return 0;
}