#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 1004

int a, b, c, d, e, m, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
long long memo2[MAX_N] = { -1 };

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
    memo[1] = 1;
    memo[2] = 2;
    memo2[1] = 2;
    memo2[2] = 7;

    for (int i = 3; i < MAX_N; i++) {
        long long p = pow(2, i);
        memo[i] = memo[i - 1] + memo[i - 2];
        memo[i] %= 10007;

        memo2[i] = 1 + p * memo[i] - i;
        memo2[i] %= 1000000007;
    }


    cin >> a;
    cout << memo2[a];
    return 0;
}