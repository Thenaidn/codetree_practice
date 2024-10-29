#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 1000005
#define MOD 10007

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[MAX_N] = { 0, };
vector<pair<int, int>> arr;


void initialize() {
    for (int i = 0; i < MAX_N; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> b >> a;
    for (int i = 0; i < b; i++) {
        cin >> c >> d;
        arr.push_back({ c,d });
    }

    initialize();



    for (pair<int, int> p : arr) {
        int c = p.first; int d = p.second;

        for (int i = MAX_N - 1; i >= c; i--) {
            if (dp[i - c] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - c] + d);
            }
            
        }
    }

    int res = INT_MAX;
    for (int i = a; i < MAX_N; i++) {
        res = min(res, dp[i]);
    }

    if (res == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }

    return 0;
}