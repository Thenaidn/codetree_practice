#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 1001
#define MOD 1000000007

int n, m;
int treasure[MAX_N][101];
int dp[MAX_N][101];

void initialize() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        dp[1][i] = treasure[0][i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> treasure[i][j];
        }
    }

    initialize();

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                if (j != k) {
                    int tmp = dp[i - 1][k] + treasure[i - 1][j];
                    dp[i][j] = max(dp[i][j], tmp);
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        res = max(res, dp[n][i]);
    }

    cout << res;
    return 0;
}