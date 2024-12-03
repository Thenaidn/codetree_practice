#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> edges[MAXN];
bool visited[MAXN];

bool bfs(int start, int end, int minS, int n) {
    fill(visited, visited + n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) return true;

        for (auto &[next, weight] : edges[current]) {
            if (!visited[next] && weight >= minS) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, start, end;
    cin >> n >> m >> start >> end;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }

    // 이진 탐색
    int left = 1, right = 1e9, answer = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (bfs(start, end, mid, n)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer;
    return 0;
}
