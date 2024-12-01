#include <iostream>
#include <vector>
#include <cstring> // memset 사용을 위해 추가
#include <set>
using namespace std;

const int MAXN = 100001; // 최대 노드 수
const int MAX_H = 17;   // 2^16 > 50000, LCA를 계산할 수 있는 최대 깊이
vector<int> tree[MAXN];
int parent[MAX_H][MAXN]; // 부모 정보
int depth[MAXN];         // 깊이 정보
bool visited[MAXN];      // 방문 여부
set<int> painted;

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

    int k; cin >> k;
    while(k--){
        int a; cin >> a; painted.insert(a);
    }

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
        int cnt = 0;
        int u, v;
        cin >> u >> v;
        int lca = findLCA(u, v);
        
        while(u != lca){
            if(painted.find(u) != painted.end()){cnt++;}
            u = parent[0][u];
        }
        while(v != lca){
            if(painted.find(v) != painted.end()){cnt++;}
            v = parent[0][v];
        }
        if(painted.find(lca) != painted.end()){cnt++;}

        cout << cnt << endl;
    }

    return 0;
}
