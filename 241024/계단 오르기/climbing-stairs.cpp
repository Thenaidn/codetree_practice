#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

#define MAX_N 1004

int a, b, c, d, e, m, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int memo[MAX_N] = { -1 };

int calc(int n) {
    if (memo[n] != -1)
        return memo[n];
    if (n <= 3) {
        return 1;
    }
    else
        memo[n] = min(memo[n - 2], memo[n - 3]) + 1;
    return memo[n];                           
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < MAX_N; i++) { memo[i] = -1; }
    memo[0] = INT_MAX;
    memo[1] = INT_MAX;
    memo[2] = 1;
    memo[3] = 1;

    cin >> a;
    if (a < 2) { cout << 0; return 0; }

    cout << calc(a) % 10007;
    return 0;
}