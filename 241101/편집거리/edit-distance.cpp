#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 1001
#define MOD 1000000007

int n, m;
int treasure[MAX_N][101];
int dp[MAX_N][MAX_N];
string a; string b;

void initialize() {
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
}


int main() {
    string a, b;
    cin >> a >> b;
    n = a.size();
    m = b.size();

    initialize();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1 });
            }
        }
    }
    cout << dp[n][m];
    return 0;
}