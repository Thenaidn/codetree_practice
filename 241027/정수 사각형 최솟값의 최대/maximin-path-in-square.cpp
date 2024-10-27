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
    int m = aa[0][0];
    dp[0][0] = m;

    for (int i = 1; i < a; i++) {
        m = min(aa[0][i], m);
        dp[0][i] = m;
    }

    m = aa[0][0];

    for (int i = 1; i < a; i++) {
        m = min(aa[i][0], m);
        dp[i][0] = m;

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
    
    initialize();

    for (int i = 1; i < a; i++) {
        int m = dp[i][0];
        for (int j = 1; j < a; j++) {
            m = min(m, dp[i - 1][j]);
            dp[i][j] = m;
        }
    }

    

    cout << max(dp[a - 2][a - 1], dp[a - 1][a - 2]);
    return 0;
}