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


int step[MAX_N][MAX_N] = { 0 };
int answer[MAX_N][MAX_N] = { 0 };
bool visited[MAX_N][MAX_N] = { false };
int order = 0;
queue<pair<int, int>> q;

bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < b;
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

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isinside(ny, nx)) {
                if (step[ny][nx] == 1 && !visited[ny][nx]) {
                    push(ny, nx, answer[y][x] + 1);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> step[i][j];
        }
    }

    push(0, 0, 0);
    bfs();

    if (answer[a - 1][b - 1] == 0) { cout << -1; }
    else { cout << answer[a - 1][b - 1]; }
    //cout << ans;
    return 0;
}