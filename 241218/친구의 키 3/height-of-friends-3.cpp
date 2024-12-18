#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define MAXN 100001

int n, m;
vector<int> edges[MAXN];
bool visited[MAXN], in_stack[MAXN];
stack<int> reversed_order;
bool has_cycle = false;

// DFS 탐색
void DFS(int node) {
    visited[node] = true;
    in_stack[node] = true;

    for (int next : edges[node]) {
        if (!visited[next]) {
            DFS(next);
        } else if (in_stack[next]) {
            has_cycle = true;
        }
    }

    in_stack[node] = false;
    reversed_order.push(node);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }


    if (has_cycle) {
        cout << -1 << endl;
    } else {
        while (!reversed_order.empty()) {
            cout << reversed_order.top() << " ";
            reversed_order.pop();
        }
        cout << endl;
    }

    return 0;
}
