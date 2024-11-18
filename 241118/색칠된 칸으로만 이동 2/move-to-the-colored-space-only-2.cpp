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
bool visited[VERTICES_NUM][VERTICES_NUM] = { false };
int color[VERTICES_NUM][VERTICES_NUM] = { 0 };

int order = -1;
queue<pair<int, int>> q;
int cnt = 0; int cntc;
bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < b;
}
bool cango(int ny, int nx, int y, int x, int mid) {
    if (!isinside(ny, nx)) { return false; }
    if (visited[ny][nx] || abs(grid[y][x] - grid[ny][nx]) > mid) {
        return false;
    }
    return true;
}
void push(int y, int x) {
    answer[y][x] = order--;
    visited[y][x] = true;
    q.push(make_pair(y, x));
}

void bfs(int mid) {
    while (!q.empty()) {
        pair<int, int> cp = q.front();
        q.pop();

        int y = cp.first;
        int x = cp.second;
        if (color[y][x] == 1) { cnt++; }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (cango(ny, nx, y, x, mid)) {
                push(ny, nx);
                
            }
        }
    }
}


bool IsPossible(int mid) {
    push(c, d);
    bfs(mid);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            visited[i][j] = false;
        }
    }

    if (cnt != cntc) { 
        cnt = 0;
        return false; 
    }
    cnt = 0;
    return true;
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
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> color[i][j];
            if (color[i][j] == 1) { cntc++;  c = i; d = j; }
        }
    }
    int left = 1;
    int right = 1000000000;
    int ans = 1000000000;

    while (left <= right) { 
        int mid = (left + right) / 2;
        if (IsPossible(mid)) {
            right = mid - 1;
            ans = min(ans, mid); 
        }
        else
            left = mid + 1;
    }

    cout << ans;
    
    

    return 0;
}
