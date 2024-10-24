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

int maps[MAX_N][MAX_N] = { 0 };
int answer[MAX_N][MAX_N] = { 0 };
int visited[MAX_N][MAX_N] = { 0 };
int order = 0;
queue<pair<int, int>> q;
vector<pair<int, int>> points;
vector<int> ans;
bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}

void push(int y, int x, int s) {

    if (answer[y][x] > 0) { answer[y][x] = min(s, answer[y][x]); }
    else { answer[y][x] = s; }
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
                if (visited[ny][nx] == 0) {
                    if (maps[ny][nx] == 1) {
                        push(ny, nx, answer[y][x] + 1);
                    }
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
            cin >> maps[i][j];
            if (maps[i][j] == 0) { answer[i][j] = -1; }
            if (maps[i][j] == 2) { points.push_back(make_pair(i, j)); }
        }
    }
    for (pair<int, int> p : points) {
        push(p.first, p.second, 0);
        bfs();
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                visited[i][j] = 0;
            }
        }
    }


    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (answer[i][j] == 0 && maps[i][j] == 1) { cout << -2 << " "; }
            else { cout << answer[i][j] << " "; }
        }
        cout << endl;
    }
    //cout << ans;
    return 0;
}