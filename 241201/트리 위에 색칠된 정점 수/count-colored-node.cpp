#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

const int MAXN = 100001; // 최대 노드 수
const int MAX_H = 17;   // 2^16 > 50000, LCA를 계산할 수 있는 최대 깊이
vector<int> tree[MAXN];
int parent[MAX_H][MAXN]; // 부모 정보
int depth[MAXN];         // 깊이 정보
bool visited[MAXN];      // 방문 여부
unordered_map<int, bool> painted; // 색칠된 노드 정보

// DFS를 통해 깊이와 1차 부모 설정
void dfs(int node, int d) {
    visited[node] = true;
    depth[node] = d;

    for (int child : tree[node]) {
        if (!visited[child]) {
            parent[0][child] = node; // 1차 부모 설정
            dfs(child, d + 1);       // 자식으로 이동
        }
    }
}

// LCA 계산
int findLCA(int a, int b) {
    // 깊이를 동일하게 맞추기
    if (depth[a] < depth[b]) swap(a, b);
    for (int h = MAX_H - 1; h >= 0; h--) {
        if (depth[a] - depth[b] >= (1 << h))
            a = parent[h][a];
    }

    // 공통 조상을 찾을 때까지 부모로 이동
    if (a == b) return a;

    for (int h = MAX_H - 1; h >= 0; h--) {
        if (parent[h][a] != parent[h][b]) {
            a = parent[h][a];
            b = parent[h][b];
        }
    }

    // 최종 공통 조상 반환
    return parent[0][a];
}

// 경로 상의 색칠된 노드 수 계산
int countPaintedOnPath(int u, int v, int lca) {
    unordered_map<int, bool> seen;
    int count = 0;

    // 경로 u -> lca
    while (u != lca) {
        if (painted[u] && !seen[u]) {
            count++;
            seen[u] = true;
        }
        u = parent[0][u];
    }

    // 경로 v -> lca
    while (v != lca) {
        if (painted[v] && !seen[v]) {
            count++;
            seen[v] = true;
        }
        v = parent[0][v];
    }

    // lca 처리
    if (painted[lca] && !seen[lca]) count++;

    return count;
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

    // 초기화
    memset(parent, 0, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    memset(visited, false, sizeof(visited));

    // 색칠된 노드 입력
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        painted[a] = true;
    }

    // DFS로 깊이 및 1차 부모 설정
    dfs(1, 0);

    // 2^h 부모 정보 설정
    for (int h = 1; h < MAX_H; h++) {
        for (int i = 1; i <= n; i++) {
            if (parent[h - 1][i] != 0)
                parent[h][i] = parent[h - 1][parent[h - 1][i]];
        }
    }

    // 쿼리 처리
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int lca = findLCA(u, v);

        // 경로 상의 색칠된 노드 수 계산
        cout << countPaintedOnPath(u, v, lca) << endl;
    }

    return 0;
}
