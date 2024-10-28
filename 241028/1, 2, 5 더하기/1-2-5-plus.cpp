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
int arr[3] = { 1,2,5 };

vector<pair<pair<int, int>, int>> lines;

void initialize() {
    for (int i = 0; i <= a; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    b = 3;
    arr[0] = 1;
    //for (int i = 1; i <= b; i++) {
    //    cin >> arr[i];
    //}

    initialize();

    for (int i = 1; i <= a; i++) {
        for (int j = 0; j < b; j++) {
            if (i >= arr[j]) {
                dp[i] = (dp[i] + dp[i - arr[j]]) % MOD;
            }
        }
    }

    int res = dp[a];
    if (res == INT_MIN) { res = -1; }

    cout << res;
    return 0;
}