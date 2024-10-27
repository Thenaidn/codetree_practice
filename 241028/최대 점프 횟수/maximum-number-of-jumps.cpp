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

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[MAX_N] = { 0, };
int arr[MAX_N];



void initialize() {
    for (int i = 0; i < a; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }

    initialize();

    for (int i = 1; i < a; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == INT_MIN) { continue; }
            if (j + arr[j] >= i) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
           
        }
    }
    
    int res = 0;

    for (int i = 0; i < a; i++) { res = max(res, dp[i]); }
    cout << res;
    return 0;
}