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
int dp[MAX_N] = {0,};
int arr[MAX_N];

vector<pair<pair<int, int>, int>> lines;

void initialize() {
    for (int i = 0; i <= a; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> b >> a;
    arr[0] = 0;
    for (int i = 1; i <= b; i++) {
        cin >> arr[i];
    }

    initialize();

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i >= arr[j]) {
                if (dp[i - arr[j]] == INT_MAX) { continue; }
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }
    
    int res = dp[a];
    if (res == INT_MAX) { res = -1; }

    cout << res;
    return 0;
}