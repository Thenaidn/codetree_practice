#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 1001
#define MOD 1000000007

int n, m;
vector<pair<pair<int, int>, int>> shirts;
int dp[MAX_N][10];

void initialize() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = 0;
        }
    }
    for (int j = 1; j < 10; j++) {
        dp[1][j] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    initialize();

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            if (j < 9) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < 10; i++) {

            res = (res + dp[n][i])%MOD;
        
    }

    cout << res;
    return 0;
}