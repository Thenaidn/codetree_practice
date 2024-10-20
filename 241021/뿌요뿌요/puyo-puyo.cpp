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
vector<int> answer;
int res = 0;
int maps[1001][1001];
int tmpmaps[20][20] = { 0, };
vector<pair<int, int>> points;
bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < b;
}


int dfs(int y, int x, int k) {
    visited[y][x] = true;
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isinside(ny, nx) && maps[ny][nx] == k && !visited[ny][nx]) {
            cnt += dfs(ny, nx, k);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    b = a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> maps[i][j];
        }
    }

    int res = 0;
    int ans = 0;


    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (!visited[i][j]) {
                int size = dfs(i, j, maps[i][j]);
                if (size >= 4) {
                    res++;
                }
                ans = max(ans, size);
            }
        }
    }


    
    cout << res << " " << ans;

    return 0;
}