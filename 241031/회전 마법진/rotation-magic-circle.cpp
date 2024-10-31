#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 10001
#define MOD 1000000007

int n, m;
string before;
string after;

int dp[MAX_N][10];
int cw[10] = { 0, };
int ccw[10] = { 0, };

void initialize() {
    for (int i = 0; i < n; i++) {
        int n1 = before[i] - '0'; int n2 = after[i] - '0';
        int sub = abs(n1 - n2);
        cw[sub]++;
    }
    int max_s = cw[0];
    for (int i = 1; i < 10; i++) {
        max_s = max(max_s, cw[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (cw[i] != max_s) {
            cw[i] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> before >> after;


    initialize();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (cw[j] == -1) { continue; }

            int n1 = before[i] - '0'; int n2 = after[i] - '0';
            int sub = abs(n1 - n2 + cw[j]);
            
            ccw[j] += sub;
        }
        

    }

    int res = 0;
    for (int j = 0; j < 10; j++) {
        res = max(res, cw[j] + ccw[j]);
    }

    cout << res;
    return 0;
}