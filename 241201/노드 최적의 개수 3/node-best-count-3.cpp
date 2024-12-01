#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int MAXN = 100000;
vector<int> tree[MAXN + 1];
int dp[MAXN + 1];
bool visited[MAXN + 1];
int res = 0;
int n, s, d;

vector<pair<int, int>> v;
map<int, int> treemap;
set<int> selected;

void dfs(int node) {
    visited[node] = true;


    dp[node] = 1;

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child);

            dp[node] = max(dp[child] + 1, dp[node]);

        }
    }
}
void dfs2(int node, int d, int& res) {
    visited[node] = true;
    bool needPaint = (dp[node] > d);

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs2(child, d, res);
            if (dp[child] > d) {
                needPaint = true;
            }
        }
    }


    if (needPaint && node != s) {
        res += 2;
    }
}

int main() {

    cin >> n;
    d = 1;

    // 트리 입력
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        v.push_back({ a, b });
    }



    for (pair<int, int> i : v) {
        bool first = false;
        bool second = false;

        for (int j : tree[i.first]) {
            if (selected.find(j) != selected.end()) {
                first = true;
                break;
            }
        }
        for (int j : tree[i.second]) {
            if (selected.find(j) != selected.end()) {
                second = true;
                break;
            }
        }
        if (!first && !second) {
            if (tree[i.first].size() > tree[i.second].size()) {
                selected.insert(i.first);
            }
            else { selected.insert(i.second); }
        }
    }


    cout << selected.size() << endl;

    return 0;
}


