#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 1004

int a, b, c, d, e, m, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
long long dp[MAX_N] = { -1 };
long long dp2[MAX_N] = { -1 };

int calc(int n) {
    if (memo[n] != -1)
        return memo[n];
    if (n <= 3) {
        return 1;
    }
    else
        memo[n] = min(memo[n - 2], memo[n - 3]) + 1;
    return memo[n];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < MAX_N; i++) { memo[i] = -1; }
    memo[1] = 1;
    memo[2] = 2;
    dp[1] = 2;
    dp[2] = 7;
    dp2[1] = 1;
    dp2[2] = 3;

    for (int i = 3; i < MAX_N; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] + dp2[i - 1] * 2) % 1000000007;
        dp2[i] = (dp[i - 1] + dp2[i - 1]) % 1000000007;
    }


    cin >> a;
    cout << dp[a];
    return 0;
}