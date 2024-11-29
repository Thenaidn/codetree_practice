#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

const int MAXN = 100000;
set<int> tree[MAXN + 1];
int dp[MAXN + 1];
bool visited[MAXN + 1];

int center = 0;

int biggest = 0; int smallest = INT_MAX;

void dfs(int node, int parent) {
    if (center != 0) { return; }
    int size = tree[node].size();
    if (tree[node].find(parent) != tree[node].end()) { size--; }
    if (size >= 2) {
        center = node;
        return;
    }
    
    visited[node] = true;


    //dp[node] = 1;



    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child, node);

            //dp[node] += dp[child];

        }
    }

    
    if (center != 0) { return; }
    center = node; 
}

void dfs2(int node) {
    visited[node] = true;


    dp[node] = 1;

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs2(child);

            dp[node] += dp[child];

        }
    }
}

int main() {
    int n, r, q;
    cin >> n >> r;

    // 트리 입력
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].insert(b);
        tree[b].insert(a);
    }

    dfs(r, -1);

    for (int i = 0; i < 100001; i++) { visited[i] = false; }

    dfs2(center);

    for (int i : tree[center]) {
        biggest = max(biggest, dp[i]);
        smallest = min(smallest, dp[i]);
    }

    cout << biggest - smallest;



    //cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}
