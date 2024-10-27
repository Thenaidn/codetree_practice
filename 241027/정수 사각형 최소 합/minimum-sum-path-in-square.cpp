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

int a, b, c, d, e, m, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[MAX_N][MAX_N];
int aa[MAX_N][MAX_N];

void initialize() {
    dp[0][a - 1] = aa[0][a - 1];

    for (int i = a - 2; i >= 0; i--) {
        dp[0][i] = dp[0][i + 1] + aa[0][i];
        
    }
    for (int i = 1; i < a; i++) {
        //dp[i][0] = dp[i - 1][0] + aa[i][0];
        dp[i][a - 1] = dp[i - 1][a - 1] + aa[i][a - 1];
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> aa[i][j];
            dp[i][j] = 0;
        }
    }
    
    initialize();

    for (int i = 1; i < a; i++) {
        for (int j = a - 2; j >= 0; j--) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + aa[i][j];
        }
    }

    /*int ans = INT_MIN;
    for (int j = 0; j < n; j++) {
        ans = max(ans, dp[n - 1][j]);
    }*/

    cout << dp[a - 1][0];
    return 0;
}