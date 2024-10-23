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
int result[MAX_N][MAX_N] = { 0 };
bool visited[MAX_N][MAX_N] = { false };
int order = 0;
queue<pair<int, int>> q;
vector<pair<int, int>> points;
vector<pair<int, int>> endpoints;

bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}

void push(int y, int x, int s) {
    answer[y][x] = s;
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
                if (!visited[ny][nx] && step[ny][nx] != 1) {
                    push(ny, nx, answer[y][x] + 1);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> step[i][j];
            if (step[i][j] == 2) {
                points.push_back(make_pair(i, j));
            }
            if (step[i][j] == 3) {
                endpoints.push_back(make_pair(i, j));
            }
        }
    }
    for (pair<int, int> p : points) {
        push(p.first, p.second, 0);
        bfs();

        for (pair<int, int> ep : endpoints) {
            if (answer[ep.first][ep.second] == 0) {
                if (result[p.first][p.second] == 0) {
                    result[p.first][p.second] = -1;
                }
            }
            else { 
                if (result[p.first][p.second] == -1 || result[p.first][p.second] == 0) {
                    result[p.first][p.second] = answer[ep.first][ep.second];
                }
                else {
                    result[p.first][p.second] =
                        min(answer[ep.first][ep.second], result[p.first][p.second]);
                }
            }
        }
        

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                answer[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    //cout << ans;
    return 0;
}