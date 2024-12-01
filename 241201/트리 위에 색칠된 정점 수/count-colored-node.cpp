#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;
const int LOG = 17; // log2(MAX_N) ≈ 16.6

vector<int> tree[MAX_N + 1];
int parent[MAX_N + 1][LOG + 1];
int depth[MAX_N + 1];
int in_time[MAX_N + 1], out_time[MAX_N + 1], euler_time = 0;
set<int> colored_nodes;

// DFS로 깊이 및 Euler Tour 시간 기록
void dfs(int node, int par) {
    in_time[node] = ++euler_time;
    parent[node][0] = par;
    depth[node] = depth[par] + 1;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
    out_time[node] = euler_time;
}

// LCA 전처리
void preprocess(int n) {
    for (int j = 1; j <= LOG; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

// LCA 계산
int find_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i <= LOG; i++) {
        if ((diff >> i) & 1) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;

    for (int i = LOG; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

// 트리 경로에서 색칠된 노드의 개수 계산
int count_colored_on_path(int u, int v) {
    set<int> path_nodes;
    int lca = find_lca(u, v);

    // u -> lca 경로
    while (u != lca) {
        if (colored_nodes.count(u)) path_nodes.insert(u);
        u = parent[u][0];
    }
    // v -> lca 경로
    while (v != lca) {
        if (colored_nodes.count(v)) path_nodes.insert(v);
        v = parent[v][0];
    }
    // LCA 자체도 확인
    if (colored_nodes.count(lca)) path_nodes.insert(lca);

    return path_nodes.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 트리 입력 처리
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= LOG; j++) {
            parent[i][j] = -1;
        }
    }

    // DFS 및 LCA 전처리
    dfs(1, 0);
    preprocess(n);

    // 색칠된 노드 입력 처리
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        colored_nodes.insert(c);
    }

    // 쿼리 처리
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << count_colored_on_path(u, v) << "\n";
    }

    return 0;
}
