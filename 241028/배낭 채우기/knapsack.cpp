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

    cin >> b >> a;
    for (int i = 0; i < b; i++) {
        cin >> c >> d;
        arr.push_back({ c,d });
    }

    initialize();



    for (pair<int,int> p : arr) {
        int c = p.first; int d = p.second;

        for (int i = a; i >= c; i--) {
            dp[i] = max(dp[i], dp[i - c] + d);
        }
    }
    int res = dp[a];

    cout << res;
    
    return 0;
}