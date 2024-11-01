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

int alen; int blen;

void initialize() {
    dp[1][1] = (a[1] == b[1]) ? 1 : 0;
    for (int i = 2; i <= alen; i++) {
        if (a[i] == b[1]) {
            dp[i][1] = 1;
        }
        /*else {
            dp[i][1] = dp[i - 1][1];
        }*/
    }
    for (int i = 2; i <= blen; i++) {
        if (a[1] == b[i]) {
            dp[1][i] = 1;
        }
        /*else {
            dp[1][i] = dp[1][i - 1];
        }*/
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    int alen = a.length(), blen = b.length();

    for (int i = 1; i <= alen; i++) {
        for (int j = 1; j <= blen; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[alen][blen] << '\n';
    return 0;
}