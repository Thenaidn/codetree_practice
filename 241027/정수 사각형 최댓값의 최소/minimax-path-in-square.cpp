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
int aa[MAX_N][MAX_N];



void initialize() {
    dp[0][0] = aa[0][0];

    for (int i = 1; i < a; i++) {
        dp[0][i] = max(dp[0][i - 1], aa[0][i]);
        dp[i][0] = max(dp[i - 1][0], aa[i][0]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> aa[i][j];
        }
    }

    if (a == 1) { cout << aa[0][0]; return 0; }

    initialize();

    for (int i = 1; i < a; i++) {
        for (int j = 1; j < a; j++) {
            int m = min(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = max(m, aa[i][j]);
        }
    }

    cout << dp[a - 1][a - 1];
    return 0;
}