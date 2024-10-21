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

#define VERTICES_NUM 1005
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
bool cango(int y, int x) {
    if (!isinside(y, x)) { return false; }
    if (visited[y][x] || grid[y][x] == 1) {
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
            if (cango(ny, nx)) {
                push(ny, nx);
            }
        }
    }
}

int n = 2;
vector<int> ansr;

vector<int> stonecombi[1001];
int stonecombicount = 0;
vector<pair<int, int>> stones;

void Choose(int curr_num, int previous) {
    if (curr_num == m + 1) {
        for (int i = 0; i < ansr.size(); i++) {
            stonecombi[stonecombicount].push_back(ansr[i]);
        }
        stonecombicount++;
        return;
    }

    for (int i = 0; i < stones.size(); i++) {
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



    cin >> a >> b >> m;
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) { 
                stones.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < b; i++) {
        cin >> c >> d;
        points.push_back(make_pair(c - 1, d - 1));
    }
    bfs();

    Choose(1, -1);

    int ans = 0;
    for (int k = 0; k < stonecombicount; k++) {
        for (int i = 0; i < m; i++) {
            int y = stones[stonecombi[k][i]].first;
            int x = stones[stonecombi[k][i]].second;
            grid[y][x] = 0;
        }
        

        for (int i = 0; i < b; i++) {
            
            push(points[i].first, points[i].second);
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

        for (int i = 0; i < m; i++) {
            int y = stones[stonecombi[k][i]].first;
            int x = stones[stonecombi[k][i]].second;
            grid[y][x] = 1;
        }
    }
    


    cout << ans;
    return 0;
}