#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 10005
#define MOD 10007

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[MAX_N] = { 0, };
vector<pair<int, int>> arr;


void initialize() {
    for (int i = 0; i <= a; i++) {
        dp[i] = 0;
    }
    dp[0] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> b;
    a = b;
    for (int i = 1; i <= b; i++) {
        cin >> d;
        arr.push_back({ i,d });
    }

    initialize();



    for (pair<int, int> p : arr) {
        int c = p.first; int d = p.second;

        for (int i = c; i <= a; i++) {
            dp[i] = max(dp[i], dp[i - c] + d);
        }
    }
    int res = dp[a];

    cout << res;

    return 0;
}