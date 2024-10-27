#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 505
#define MOD 10007

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int memo[MAX_N] = { -1 };
int dp[MAX_N][MAX_N] = { 0, };
int maps[MAX_N][MAX_N];

bool isinside(int y, int x) {
    return y >= 0 && x >= 0 && y < a && x < a;
}

void initialize() {
    dp[0][0] = maps[0][0];

    for (int i = 1; i < a; i++) {
        dp[0][i] = min(dp[0][i - 1], maps[0][i]);
        dp[i][0] = min(dp[i - 1][0], maps[i][0]);
    }
}

int dfs(int y, int x) {
    if (dp[y][x] != -1) { return dp[y][x]; }
    dp[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if (isinside(ny, nx)) {
            if (maps[y][x] < maps[ny][nx]) {
                dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
            }
        }

    }
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> maps[i][j];
            dp[i][j] = -1;
        }
    }

    if (a == 1) { cout << 1; return 0; }

    int m = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            m = max(m, dfs(i, j));
        }
    }

    cout << m;
    return 0;
}