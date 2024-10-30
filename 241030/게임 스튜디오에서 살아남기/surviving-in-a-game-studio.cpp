#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007
int n;
long long dp[1001][3][3] = { 0 };
void initialize() {
    dp[0][0][0] = 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    initialize();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (dp[i][j][k] == 0) { continue; }

                dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % MOD;
                if (j < 2) {
                    dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % MOD;
                }
                if (k < 2) {
                    dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % MOD;
                }
            
            }
        }

    }
    long long res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res = (res + dp[n][i][j]) % MOD;
        }
    }
    cout << res;
    return 0;
}