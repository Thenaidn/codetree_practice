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
#define LOW_INT -10001

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[10][MAX_N] = { 0, };
vector<int> arr;

bool ans[MAX_N] = { false, };

bool isinside(int n) {
    return n >= 0 && n < a;
}

void initialize() {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= b; j++) {
            dp[j][i] = LOW_INT;
        }
    }
    dp[0][0] = arr[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> c;
        arr.push_back(c);
    }

    initialize();

    for (int i = 1; i < a; i++) {
        //arr[i]
        int sum1 = 0; int sum2 = 0;
        for (int j = 0; j <= b; j++) {
            if (arr[i] > 0) {
                dp[j][i] = max(dp[j][i - 1] + arr[i], arr[i]);
            }
            else {
                if (j + 1 <= b) {
                    dp[j + 1][i] = max(dp[j][i - 1] + arr[i], arr[i]);
                }
                /*else {
                    dp[0][i] = max(dp[0][i], arr[i]);
                }*/
            }
        }
    }

    int res = LOW_INT;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= b; j++) {
            res = max(res, dp[j][i]);

        }
    }

    cout << res;
    return 0;
}