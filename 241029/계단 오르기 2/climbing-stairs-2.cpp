#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 1005
#define MOD 10007
#define ZERO 0

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[4][MAX_N] = { 0, };
vector<int> arr;

bool ans[MAX_N] = { false, };

bool isinside(int n) {
    return n >= 0 && n < a;
}

void initialize() {
    for (int i = 0; i < a; i++) {
        dp[0][i] = INT_MIN;
        dp[1][i] = INT_MIN;
        dp[2][i] = INT_MIN;
        dp[3][i] = INT_MIN;
    }
    dp[1][0] = arr[0];
    dp[0][1] = arr[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        arr.push_back(b);
    }

    initialize();

    for (int i = 1; i < a; i++) {
        for (int j = 0; j < 4; j++) {
            if (j < 3) {
                if (dp[j][i - 1] != INT_MIN) {
                    dp[j + 1][i] = max(dp[j][i - 1] + arr[i], dp[j + 1][i]);
                }
            }
            if (i > 1) {
                if (dp[j][i - 2] != INT_MIN) {
                    dp[j][i] = max(dp[j][i - 2] + arr[i], dp[j][i]);
                }
            }
            
        }
    }

    int res = INT_MIN;

        for (int j = 0; j < 4; j++) {
            res = max(res, dp[j][a - 1]);

        }


    cout << res;
    return 0;
}