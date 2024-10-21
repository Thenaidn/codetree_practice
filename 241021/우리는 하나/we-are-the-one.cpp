#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

int a, b, c, d, e, m;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

#define VERTICES_NUM 10
#define EDGES_NUM 6

int grid[VERTICES_NUM][VERTICES_NUM] = { 0 };
int answer[VERTICES_NUM][VERTICES_NUM];
bool visited[VERTICES_NUM][VERTICES_NUM] = { false };
int order = -1;
queue<pair<int, int>> q;
vector<pair<int, int>> points;

bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}
bool cango(int y, int x, int ny, int nx) {
    if (!isinside(ny, nx)) { return false; }
    if (visited[ny][nx] || 
        abs(grid[y][x] - grid[ny][nx]) > d || 
        abs(grid[y][x] - grid[ny][nx]) < c) {
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
        pair<int, int> cp = q.front();
        q.pop();

        int y = cp.first;
        int x = cp.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (cango(y, x, ny, nx)) {
                push(ny, nx);
            }
        }
    }
}

int n = 2;
vector<int> ansr;

vector<int> citycombi[1001];
int citycombicount = 0;
vector<pair<int, int>> citys;

void Choose(int curr_num, int previous) {
    if (curr_num == b + 1) {
        for (int i = 0; i < ansr.size(); i++) {
            citycombi[citycombicount].push_back(ansr[i]);
        }
        citycombicount++;
        return;
    }

    for (int i = 0; i < a * a; i++) {
        if (i <= previous) { continue; }
        ansr.push_back(i);
        Choose(curr_num + 1, i);
        ansr.pop_back();

    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    cin >> a >> b >> c >> d;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> grid[i][j];
            citys.push_back(make_pair(i, j));
        }
    }

    Choose(1, -1);

    int ans = 0;
    for (int k = 0; k < citycombicount; k++) {
        int y, x;
        for (int i = 0; i < b; i++) {
            y = citys[citycombi[k][i]].first;
            x = citys[citycombi[k][i]].second;
            push(y, x);
        }

        bfs();

        int res = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                if (answer[i][j] < 0) {
                    res++;
                    answer[i][j] = 0;
                }
                visited[i][j] = false;
            }
        }
        ans = max(ans, res);


    }



    cout << ans;
    return 0;
}