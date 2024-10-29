#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 100005
#define MOD 10007
#define LOW_INT -9

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[101][MAX_N] = { 0, };
vector<int> arr;
bool isinside(int n) {
    return n >= 0 && n < a;
}

void initialize() {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= 41; j++) {
            dp[j][i] = 0;
        }
    }
    dp[0][arr[0] + 20] = 1;
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> c;
        arr.push_back(c);
    }

    initialize();

    for (int i = 1; i < a; i++) {
        for (int sum = -20; sum <= 20; sum++) {
            int idx = sum + 20;
            if (dp[i - 1][idx] > 0) {
                int plus_sum = sum + arr[i];
                if (plus_sum >= -20 && plus_sum <= 20) {
                    dp[i][plus_sum + 20] += dp[i - 1][idx];
                }
                int minus_sum = sum - arr[i];
                if (minus_sum >= -20 && minus_sum <= 20) {
                    dp[i][minus_sum + 20] += dp[i - 1][idx];
                }
            }
        }
    }

    int res = dp[a - 1][b + 20] + 1;

    cout << res;
    return 0;
}