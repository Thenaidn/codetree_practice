#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 1001
#define MOD 1000000007

int n;
vector<pair<int, int>> students;
long long dp[MAX_N][12][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        students.push_back({ a,b });
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 11; j++) {
            for (int k = 0; k <= 9; k++) {
                dp[i][j][k] = INT_MIN;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        int soccer_skill = students[i - 1].first;
        int baseball_skill = students[i - 1].second;

        for (int j = 0; j <= 11; j++) {
            for (int k = 0; k <= 9; k++) {
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                if (j > 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + soccer_skill);
                }
                if (k > 0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + baseball_skill);
                }
            }
        }
    }

    cout << dp[n][11][9] << endl;
    return 0;
}