#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 1001
#define MOD 1000000007

int n, m;
string stones;

int dp[MAX_N][21][2];

void initialize() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }
    if (stones[0] == 'L') {
        dp[0][0][0] = 1;
    }
    else {
        dp[0][1][1] = 0;
    }
    dp[0][0][0] = (stones[0] == 'L') ? 1 : 0;
    dp[0][1][1] = (stones[0] == 'R') ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> stones;


    initialize();

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j][0] = dp[i - 1][j][0] + (stones[i] == 'L' ? 1 : 0);
            if (j > 0) {
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + (stones[i] == 'L' ? 1 : 0));
            }

            dp[i][j][1] = dp[i - 1][j][1] + (stones[i] == 'R' ? 1 : 0);
            if (j > 0) {
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] + (stones[i] == 'R' ? 1 : 0));
            }
        }
    }

    int res = 0;
    for (int j = 0; j <= m; j++) {
        res = max(res, max(dp[n - 1][j][0], dp[n - 1][j][1]));
    }

    cout << res;
    return 0;
}