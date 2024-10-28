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
int dp[MAX_N] = {0,};
vector<int> arr;

vector<pair<pair<int, int>, int>> lines;

void initialize() {
    for (int i = 0; i <= a; i++) {
        if (i <= b && arr[i] == i) {
            dp[i] = 1;
        }
        else { dp[i] = INT_MAX; }
    }
    dp[0] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> b >> a;
    arr.push_back(0);
    for (int i = 1; i <= b; i++) {
        cin >> c;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());

    initialize();

    for (int i = 1; i <= a; i++) {
        int tmp = i;
        int count = 0;
        for (int j = b; j > 0; j--) {
            if (tmp >= arr[j]) {
                tmp -= arr[j]; count++;
            }
        }
        if (tmp == 0) {
            dp[i] = min(dp[i], count);
        }
    }
    
    int res = dp[a];
    if (res == INT_MAX) { res = -1; }

    cout << res;
    return 0;
}