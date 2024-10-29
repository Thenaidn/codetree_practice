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

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[MAX_N] = { 0, };
vector<int> arr;

bool ans[MAX_N] = { false, };

void initialize() {
    for (int i = 0; i <= MAX_N; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int sum = 0;

    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> c;
        arr.push_back(c);
        sum += c;

    }

    initialize();



    for (int num : arr) {
        for (int i = MAX_N; i >= num; i--) {
            if (dp[i - num] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - num] + 1);

                if (i + i - sum == 0) {
                    cout << "Yes"; return 0;
                }
                

            }
        }
    }
    cout << "No";
    return 0;
}