#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int a, b, c, d, e;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

bool visited[1001] = {false};

int n = 0;
vector<int> answer;
int res = 0;
vector<int> maps[1001];
int tmpmaps[20][20] = { 0, };
vector<pair<int, int>> points;

void Print(vector<int> ans) {
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
int calc(vector<int>& ans) {
    int m = INT_MAX;
    for (int i = 0; i < a; i++) {
        m = min(m,maps[i][answer[i]]);
    }
    return m;
}

void dfs(int vertex, int count) {
    for (int i = 0; i < maps[vertex].size(); i++) {
        int curr_v = maps[vertex][i];
        if (!visited[curr_v]) {
            res = max(res, ++count);
            visited[curr_v] = true;
            dfs(curr_v, count);
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    for (int i = 0; i < b; i++) {
        cin >> c >> d;
        maps[c].push_back(d);
    }


    dfs(1, 0);
    cout << res;
    return 0;
}