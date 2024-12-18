#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAXN 100001

int n, m;
vector<int> edges[MAXN];
bool visited[MAXN] = {false};
bool in_stack[MAXN] = {false};

bool dfs(int node) {
    visited[node] = true;
    in_stack[node] = true;

    for (int next : edges[node]) {
        if (!visited[next]) {
            if (dfs(next)) {
                return true;
            }
        } else if (in_stack[next]) {
            return true;
        }
    }

    in_stack[node] = false;
    return false;
}

int main() {
    int o;
    cin >> n >> m >> o;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }


    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
