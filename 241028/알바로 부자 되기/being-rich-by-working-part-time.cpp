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

bool comparelines(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if (a.first.first != b.first.first) {
        return a.first.first < b.first.first;
    }
    return a.first.second < b.first.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {

        cin >> b >> c >> d;
        lines.push_back(make_pair(make_pair(b, c), d));
    }

    
    sort(lines.begin(), lines.end(), comparelines);
    int tmp = lines[0].first.second;
    //initialize();
    for (int i = 0; i < a; i++) {
        dp[i] = lines[i].second;
    }

    for (int i = 0; i < a; i++) {
        pair<int, int> p1 = lines[i].first;
        for (int j = 0; j < i; j++) {
            pair<int, int> p2 = lines[j].first;
            if (p2.second < p1.first) {
                dp[i] = max(dp[i], dp[j] + dp[i]);
            }
            else {
                dp[i] = max(dp[i], dp[j]);
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