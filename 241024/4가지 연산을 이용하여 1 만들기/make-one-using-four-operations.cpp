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

int ndy[8] = { 1, -1, 2, 2, -2, -2, -1, 1 };
int ndx[8] = { 2, 2, -1, 1, 1, -1, -2, -2 };

int number[MAX_N * MAX_N] = { 0 };
int step[MAX_N][MAX_N] = { 0 };
int answer[MAX_N * MAX_N] = { 0 };
int crush[MAX_N][MAX_N] = { -1 };
int visited[MAX_N * MAX_N] = { 0 };
int order = 0;
queue<pair<int, int>> q;
queue<int> q2;
vector<pair<int, int>> points;
vector<int> ans;
//bool isinside(int n) {
//    return y >= 0 && y < a && x >= 0 && x < a;
//}

int res = INT_MAX;
int turns = 0;
void push(int num, int cnt) {
    answer[num] = cnt;
    visited[num]++;
    q2.push(num);
}

void bfs() {
    while (!q2.empty()) {
        int cp = q2.front();
        if (cp == 1) { break; }
        q2.pop();

        for (int i = 0; i < 4; i++) {
            int n = cp;
            if (i == 2) { n--; }
            else if (i == 1) { if (n % 2 == 0) { n /= 2; } else { continue; } }
            else if (i == 0) { if (n % 3 == 0) { n /= 3; } else { continue; } }
            else { if (turns <= a) { n++; } }
           
            if (n < 1000001 && n >= 0) {
                if (visited[n] == 0) {
                    push(n, answer[cp] + 1);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;

    if (a == 1) { cout << 0; return 0; }

    push(a, 0);

    bfs();
    
    
    cout << answer[1];
    return 0;
}