#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N 55
#define MOD 10007

int a, b, c, d, e, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

long long memo[MAX_N] = { -1 };
int dp[MAX_N][MAX_N] = {0,};
int arr[MAX_N][MAX_N];

vector<pair<int, int>> lines;

void initialize() {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    dp[0][0] = 1;
}

bool comparelines(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {

        cin >> b >> c;
        lines.push_back(make_pair(b, c));
    }

    
    sort(lines.begin(), lines.end(), comparelines);
    int tmp = lines[0].second;
    //initialize();

    int res = 1;

    for (pair<int, int> p : lines) {
        if (p.first <= tmp) { 
            if (p.second >= tmp) {
                continue;
            }
            else {
                tmp = p.second;
                continue;
            }
        }
        tmp = p.second;
        res++;
    }
    
    
    //for (int i = 0; i < a; i++) {
    //    for (int j = 0; j < b; j++) {
    //        res = max(res, dp[i][j]);
    //    }
    //}

    cout << res;
    return 0;
}