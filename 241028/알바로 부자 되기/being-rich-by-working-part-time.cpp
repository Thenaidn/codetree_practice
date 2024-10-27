#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 1005
#define MOD 10007

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[MAX_N] = {0,};
int arr[MAX_N][MAX_N];

vector<pair<pair<int, int>, int>> lines;

//void initialize() {
//    for (int i = 0; i < a; i++) {
//        for (int j = 0; j < b; j++) {
//            dp[i][j] = INT_MIN;
//        }
//    }
//    dp[0][0] = 1;
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {

        cin >> b >> c >> d;
        lines.push_back({ {b,c},d });
    }


    for (int i = 0; i < a; i++) {
        dp[i] = lines[i].second;
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < i; j++) {
            if (lines[j].first.second < lines[i].first.first) {
                dp[i] = max(dp[i], dp[j] + lines[i].second);
            }
        }


        //if (p.first <= tmp) { 
        //    if (p.second >= tmp) {
        //        continue;
        //    }
        //    else {
        //        tmp = p.second;
        //        continue;
        //    }
        //}
        //tmp = p.second;
    }
    
    int res = 0;
    for (int i = 0; i < a; i++) {
            res = max(res, dp[i]);
    }

    cout << res;
    return 0;
}