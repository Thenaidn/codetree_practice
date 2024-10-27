#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 105
#define MOD 10007

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int memo[MAX_N] = { -1 };
int dp[MAX_N][MAX_N] = { 0, };
int dp2[MAX_N][MAX_N] = { 0, };
int dp3[MAX_N][MAX_N] = { 0, };
int maps[MAX_N][MAX_N];



void initialize() {
    dp[0][0] = maps[0][0];
    dp2[0][0] = maps[0][0];
    for (int i = 1; i < a; i++) {
        dp[0][i] = min(dp[0][i - 1], maps[0][i]);
        dp[i][0] = min(dp[i - 1][0], maps[i][0]);

        dp2[0][i] = max(dp2[0][i - 1], maps[0][i]);
        dp2[i][0] = max(dp2[i - 1][0], maps[i][0]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> maps[i][j];
        }
    }

    if (a == 1) { cout << 0; return 0; }

    initialize();

    for (int i = 1; i < a; i++) {
        for (int j = 1; j < a; j++) {
            if (abs(dp2[i - 1][j] - dp[i - 1][j]) <= abs(dp2[i][j - 1] - dp[i][j - 1])) {
                dp[i][j] = min(dp[i - 1][j], maps[i][j]);
                dp2[i][j] = max(dp2[i - 1][j], maps[i][j]);
            }
            else {
                dp[i][j] = min(dp[i][j - 1], maps[i][j]);
                dp2[i][j] = max(dp2[i][j - 1], maps[i][j]);
            }
        }
    }

    cout << abs(dp[a - 1][a - 1] - dp2[a-1][a-1]);
    return 0;
}