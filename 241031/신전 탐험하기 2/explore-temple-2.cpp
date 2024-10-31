#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 1001
#define MOD 1000000007

int n, m;
int treasure[MAX_N][3];
int dp[MAX_N][3][3];

void initialize() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[1][0][0] = treasure[0][0];
    dp[1][1][1] = treasure[0][1];
    dp[1][2][2] = treasure[0][2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> treasure[i][j];
        }
    }
    initialize();

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int m = 0; m < 3; m++) {
                    if (i == n && m == j) { continue; }
                    if (j != k && dp[i - 1][k][m] != 0) {
                        int tmp = dp[i - 1][k][m] + treasure[i - 1][j];
                        dp[i][j][m] = max(dp[i][j][m], tmp);
                    }
                }
                
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res = max(res, dp[n][i][j]);
        }
    }

    cout << res;
    return 0;
}