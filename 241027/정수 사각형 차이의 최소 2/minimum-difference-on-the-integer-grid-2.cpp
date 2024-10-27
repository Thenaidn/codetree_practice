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

long long memo[MAX_N] = { -1 };
int dp[MAX_N][MAX_N] = { 0, };
int maps[MAX_N][MAX_N];

int res = INT_MAX;

void initialize() {
    
}

int calc(int low) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            dp[i][j] = 1001;
        }
    }

    if (maps[0][0] < low) { return 1001; }
    dp[0][0] = maps[0][0];

    for (int i = 1; i < a; i++) {
        if (maps[i][0] >= low) {
            dp[i][0] = max(dp[i - 1][0], maps[i][0]);
        }
        if (maps[0][i] >= low) {
            dp[0][i] = max(dp[0][i - 1], maps[0][i]);
        }
    }

    for (int i = 1; i < a; i++) {
        for (int j = 1; j < a; j++) {
            if (maps[i][j] >= low) {
                dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), maps[i][j]);
            }
        }
    }
    return dp[a - 1][a - 1];
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

    if (a == 1) { cout << maps[0][0]; return 0; }

    initialize();

    
    for (int low = 1; low <= 100; low++) {
        int m = calc(low);

        if (m != 1001) {
            res = min(res, m - low);
        }
    }

    cout << res;
    return 0;
}