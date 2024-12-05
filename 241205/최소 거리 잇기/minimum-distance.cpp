#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 205

int uf[MAXN], Size[MAXN];

struct Edge {
    double weight;
    int u, v;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

// 유클리드 거리 계산
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Union-Find
int Find(int x) {
    if (x == uf[x]) return x;
    return uf[x] = Find(uf[x]);
}

void Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX != rootY) {
        if (Size[rootX] < Size[rootY]) swap(rootX, rootY);
        uf[rootY] = rootX;
        Size[rootX] += Size[rootY];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> points(n);
    vector<Edge> edges;

    // 좌표 입력
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // 이미 존재하는 간선
    for (int i = 0; i < n; i++) {
        uf[i] = i;
        Size[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Union(u - 1, v - 1); // 이미 연결된 간선 처리
    }

    // 모든 간선 추가
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // 중복 제거
            double d = dist(points[i].first, points[i].second,
                            points[j].first, points[j].second);
            edges.push_back({d, i, j});
        }
    }

    // 간선을 가중치 순으로 정렬
    sort(edges.begin(), edges.end());

    // Kruskal's MST
    double totalCost = 0.0;
    for (auto &edge : edges) {
        if (Find(edge.u) != Find(edge.v)) {
            Union(edge.u, edge.v);
            totalCost += edge.weight;
        }
    }

    printf("%.2f\n", totalCost);
    return 0;
}
