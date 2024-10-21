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
int order = -1;
queue<pair<int, int>> q;
vector<pair<int, int>> tmp;

int num = 0;

bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}
bool cango(int y, int x) {
    if (!isinside(y, x)) { return false; }
    if (visited[y][x] || grid[y][x] >= num) {
        return false;
    }
    return true;
}
void push(int y, int x) {
    answer[y][x] = order--;
    visited[y][x] = true;
    q.push(make_pair(y, x));
}

void bfs() {
    while (!q.empty()) {

        pair<int,int> cp = q.front();
        tmp.push_back(cp);
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
        for (int j = 0; j < a; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> c >> d;

    int ny = c - 1; int nx = d - 1;
    num = grid[ny][nx];
    for (int i = 0; i < b; i++) {

        push(ny, nx);
        bfs();

        int t = 0;
        sort(tmp.begin(), tmp.end());

        for (int i = tmp.size() - 1; i >= 0; i--) {
            if (tmp[i].first == c - 1 && tmp[i].second == d - 1) { continue; }
            if (grid[tmp[i].first][tmp[i].second] >= t && grid[tmp[i].first][tmp[i].second] < num) {
                t = grid[tmp[i].first][tmp[i].second];
                ny = tmp[i].first;
                nx = tmp[i].second;
            }
        }

        if (tmp.size() == 1) { cout << ny + 1 << " " << nx + 1; return 0; }
        tmp.clear();
        num = t;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                answer[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
    cout << ny + 1 << " " << nx + 1; 
    return 0;
}