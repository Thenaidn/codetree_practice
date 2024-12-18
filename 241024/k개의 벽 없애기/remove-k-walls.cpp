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

int step[MAX_N][MAX_N] = { 0 };
int answer[MAX_N][MAX_N] = { 0 };
int crush[MAX_N][MAX_N] = { -1 };
int visited[MAX_N][MAX_N] = { 0 };
int order = 0;
queue<pair<int, int>> q;
vector<pair<int, int>> points;
vector<int> ans;
bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}

void push(int y, int x, int s, int c) {
    answer[y][x] = s;
    if (y == d - 1 && x == e - 1) {
        ans.push_back(s);
    }
    if(crush[y][x] >= 0){ crush[y][x] = min(c, crush[y][x]); }
    else { crush[y][x] = c; }
    visited[y][x]++;
    q.push(make_pair(y, x));
}

void bfs() {
    while (!q.empty()) {
        pair<int, int> cp = q.front();
        q.pop();

        int y = cp.first;
        int x = cp.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isinside(ny, nx)) {
                if (visited[ny][nx] <= 4 && crush[y][x] <= k) {
                    if (step[ny][nx] == 1) {
                        push(ny, nx, answer[y][x] + 1, crush[y][x] + 1);
                    }
                    else{ push(ny, nx, answer[y][x] + 1, crush[y][x]); }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> k;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> step[i][j];
            crush[i][j] = -1;
        }
    }
    cin >> b >> c >> d >> e;
    push(b - 1, c - 1, 0, 0);
    bfs();
    
    if (answer[d - 1][e - 1] == 0) {
        cout << -1;
    }
    else {
        sort(ans.begin(), ans.end());
        cout << ans[0];
    }
    
    //cout << ans;
    return 0;
}