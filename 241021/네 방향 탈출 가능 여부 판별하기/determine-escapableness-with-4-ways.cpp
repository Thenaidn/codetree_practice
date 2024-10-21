#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

int a, b, c, d, e;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

#define VERTICES_NUM 1005
#define EDGES_NUM 6

int grid[VERTICES_NUM][VERTICES_NUM] = { 0 };
int answer[VERTICES_NUM][VERTICES_NUM];
bool visited[VERTICES_NUM][VERTICES_NUM] = {false};
int order = 1;
queue<pair<int, int>> q;

bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < b;
}
bool cango(int y, int x) {
    if (!isinside(y, x)) { return false; }
    if (visited[y][x] || grid[y][x] == 0) {
        return false;
    }
    return true;
}
void push(int y, int x) {
    answer[y][x] = order++;
    visited[y][x] = true;
    q.push(make_pair(y, x));
}

void bfs() {
    while (!q.empty()) {
        pair<int,int> cp = q.front();
        q.pop();

        int y = cp.first;
        int x = cp.second;

        for (int i = 0; i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (cango(ny, nx)) {
                push(ny, nx);
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
            cin >> grid[i][j];
        }
    }

    if (a == 1 && b == 1) { cout << 1; return 0; }

    push(0, 0);
    
    bfs();

    if (answer[a - 1][b - 1] > 1) { cout << 1; }
    else { cout << 0; }
    //cout << res << " " << ans;

    return 0;
}