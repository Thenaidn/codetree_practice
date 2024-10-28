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
vector<int> arr;


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
    for (int i = 0; i < b; i++) {
        cin >> c;
        arr.push_back(c);
    }

    initialize();



    for (int num : arr) {
        for (int i = a; i >= num; i--) {
            if (dp[i - num] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
    }
    int res = dp[a];
    if (res == INT_MAX) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
    return 0;
}