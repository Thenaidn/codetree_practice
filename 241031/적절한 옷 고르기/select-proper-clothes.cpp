#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 1001
#define MOD 1000000007

int n, m;
vector<pair<pair<int, int>, int>> shirts;
int dp[MAX_N][202];

void initialize() {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        pair<pair<int, int>, int> p = shirts[i];
        if (p.first.first == 1) {
            dp[1][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        shirts.push_back({ {a, b},c });
    }
    initialize();

    for (int i = 2; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i < shirts[j].first.first || i > shirts[j].first.second) { continue; }
            for (int k = 0; k < n; k++) {
                if (dp[i - 1][k] != -1 && j != k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] +
                        abs(shirts[k].second - shirts[j].second));
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (dp[m][i] != -1) {
            res = max(res, dp[m][i]);
        }
    }

    cout << res;
    return 0;
}