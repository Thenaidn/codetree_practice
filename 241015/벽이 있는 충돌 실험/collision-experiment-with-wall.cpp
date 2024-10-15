#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;


int a, b, c, d, e;
int dy[4] = { 0, 0, -1, 1 }; // L, R, U, D
int dx[4] = { -1, 1, 0, 0 };
vector<pair<int, int>> balls;
vector<int> dirs;

bool isinside(int y, int x) {
    return x >= 0 && x < a && y >= 0 && y < a;
}

void move_balls() {
    unordered_map<int, vector<int>> np; 
    vector<int> rm;

    for (int i = 0; i < balls.size(); i++) {
        int x = balls[i].first;
        int y = balls[i].second;
        int dir = dirs[i];

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!isinside(ny, nx)) {
            if (dir == 0) dirs[i] = 1; // L -> R
            else if (dir == 1) dirs[i] = 0; // R -> L
            else if (dir == 2) dirs[i] = 3; // U -> D
            else if (dir == 3) dirs[i] = 2; // D -> U

            nx = x;
            ny = y;
        }


        np[ny * a + nx].push_back(i);
    }


    vector<pair<int, int>> remain;
    vector<int> remaindir;

    for (auto& p : np) {
        vector<int>& ids = p.second;
        if (ids.size() == 1) { 
            int id = ids[0];
            int nx = p.first % a;
            int ny = p.first / a;
            remain.push_back({ nx, ny });
            remaindir.push_back(dirs[id]);
        }

    }


    balls = remain;
    dirs = remaindir;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        cin >> a >> b;

        balls.clear();
        dirs.clear();

        for (int i = 0; i < b; i++) {
            char dir;
            cin >> c >> d >> dir;
            c--; d--;

            balls.push_back({ d, c });
            if (dir == 'L') dirs.push_back(0);
            else if (dir == 'R') dirs.push_back(1);
            else if (dir == 'U') dirs.push_back(2);
            else if (dir == 'D') dirs.push_back(3);
        }


        for (int i = 0; i < 2 * a; i++) {
            move_balls();
        }

        cout << balls.size() << endl;
    }

    return 0;
}