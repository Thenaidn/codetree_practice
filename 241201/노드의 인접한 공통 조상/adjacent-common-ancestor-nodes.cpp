#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10001; // 최대 노드 수
vector<int> tree[MAXN];
int parent[MAXN];      // 부모 정보
int depth[MAXN];       // 깊이 정보
bool visited[MAXN];    // 방문 여부

// DFS로 부모와 깊이 정보 설정
void dfs(int node, int d) {
    visited[node] = true;
    depth[node] = d;

    for (int child : tree[node]) {
        if (!visited[child]) {
            parent[child] = node; // 부모 설정
            dfs(child, d + 1);    // 자식으로 이동
        }
    }
}

// LCA 계산
int findLCA(int u, int v) {
    // u와 v의 깊이를 동일하게 맞추기
    while(depth[u] != depth[v]) {
    if(depth[u] > depth[v])
        u = parent[u];
    else
        v = parent[v];
}

    // 공통 조상을 찾을 때까지 부모로 이동
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main() {
    int n;
    cin >> n;

    // 트리 입력
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // 루트 노드에서 시작하여 DFS 수행 (1번 노드를 루트로 가정)
    dfs(1, 0);

    // 공통 조상을 구할 두 노드 입력
    int u, v;
    cin >> u >> v;

    // LCA 출력
    cout << findLCA(u, v) << endl;

    return 0;
}
