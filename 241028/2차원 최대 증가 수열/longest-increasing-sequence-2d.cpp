#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 55
#define MOD 10007

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[MAX_N][MAX_N] = {0,};
int arr[MAX_N][MAX_N];



void initialize() {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    dp[0][0] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }

    initialize();

    for (int i = 1; i < a; i++) {
        for (int j = 1; j < b; j++) {
            for (int y = 0; y < i; y++) {
                for (int x = 0; x < j; x++) {
                    if (arr[i][j] > arr[y][x]) {
                        dp[i][j] = max(dp[i][j], dp[y][x] + 1);
                    }
                }
            }
        }
    }

    
    int res = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            res = max(res, dp[i][j]);
        }
    }

    cout << res;
    return 0;
}