#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int a, b, c, d, e;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool visited[1001][1001] = {false};
int order = 1;
int n = 0;
int answer[1001][1001] = { 0 };
int res = 0;
int maps[1001][1001];
int tmpmaps[20][20] = { 0, };
vector<pair<int, int>> points;
bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < b;
}


void dfs(int y, int x) {

    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isinside(ny, nx)) {
            if (maps[ny][nx] == 1) {
                visited[ny][nx] = true;
                dfs(ny, nx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> maps[i][j];
        }
    }


    dfs(0, 0);

    if (visited[a - 1][b - 1]) {
        cout << 1; return 0;
    }
    cout << 0;
    return 0;
}