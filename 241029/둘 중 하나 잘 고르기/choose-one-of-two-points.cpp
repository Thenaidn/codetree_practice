#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 100005
#define MOD 10007
#define LOW_INT -1

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[101][MAX_N] = { 0, };
vector<int> arr;
vector<int> arr2;
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
    dp[1][0] = arr2[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> a;
    for (int i = 0; i < a * 2; i++) {
        cin >> c >> d;
        arr.push_back(c);
        arr2.push_back(d);
    }

    initialize();

    for (int i = 1; i < a * 2; i++) {
        for (int j = 0; j <= a; j++) {
            dp[j][i] = max(dp[j][i], dp[j][i - 1] + arr[i]);
            if (j + 1 <= a) {
                dp[j + 1][i] = max(dp[j + 1][i], dp[j][i - 1] + arr2[i]);
            }
        }
    }

    /*int res = LOW_INT;
    for (int i = 0; i < a * 2; i++) {
        for (int j = 0; j <= a; j++) {
            res = max(res, dp[a][i]);

        }
    }*/

    cout << dp[a][a * 2 - 1];
    return 0;
}