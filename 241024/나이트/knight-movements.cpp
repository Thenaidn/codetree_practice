#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

#define MAX_N 1001

int a, b, c, d, e, m;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int ndy[8] = { 1, -1, 2, 2, -2, -2, -1, 1 };
int ndx[8] = { 2, 2, -1, 1, 1, -1, -2, -2 };

int step[MAX_N][MAX_N] = { 0 };
int answer[MAX_N][MAX_N] = { 0 };
bool visited[MAX_N][MAX_N] = { false };
int order = 0;
queue<pair<int, int>> q;

bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}

void push(int y, int x, int s) {
    if(answer[y][x] < s){ answer[y][x] = s; }
    visited[y][x] = true;
    q.push(make_pair(y, x));
}

void bfs() {
    while (!q.empty()) {
        pair<int, int> cp = q.front();
        q.pop();

        int y = cp.first;
        int x = cp.second;

        for (int i = 0; i < 8; i++) {
            int nx = x + ndx[i];
            int ny = y + ndy[i];
            if (isinside(ny, nx)) {
                if (!visited[ny][nx]) {
                    push(ny, nx, answer[y][x] + 1);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c >> d >> e;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            step[i][j] = 0;
        }
    }

    push(b - 1, c - 1, 0);
    bfs();

    if (answer[d - 1][e - 1] == 0) { 
        if (a == 1) { cout << 0; }
        else { cout << -1; }
    }
    else { cout << answer[d - 1][e - 1]; }
    //cout << ans;
    return 0;
}