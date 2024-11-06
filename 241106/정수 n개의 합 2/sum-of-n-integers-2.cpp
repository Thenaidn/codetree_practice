#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 11;

int arr[MAX_N] = { 0 };
int dp[MAX_N] = {0};

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++) { cin >> arr[i]; }

    int m = 0;
    for (int i = 0; i < b; i++) {
        m += arr[i];
    }
    dp[b - 1] = m;
    for (int i = b; i < a; i++) {
        dp[i] = dp[i - 1] + arr[i] - arr[i - b];
        m = max(m, dp[i]);
    }
    cout << m;
    return 0;
}