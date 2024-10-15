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
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
vector<tuple<int, int, int>> balls;
vector<int> dirs;

int maps[1111][1111];

bool isinside(int y, int x) {
    return x >= 0 && x < a && y >= 0 && y < a;
}

void remove() {
    vector<tuple<int, int, int>> new_balls;
    for (int i = 0; i < balls.size(); i++) {
        int y = get<0>(balls[i]);
        int x = get<1>(balls[i]);
        if (maps[y][x] == 1) {
            new_balls.push_back(balls[i]);
        }
        else {
            maps[y][x] = 0; 
        }
    }
    balls = new_balls;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {

        cin >> a >> b;

        balls.clear(); 

        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < a; ++j) {
                maps[i][j] = 0;
            }
        }


        for (int i = 0; i < b; ++i) {
            int x, y;
            char d;
            cin >> y >> x >> d;
            x--; y--;
            if (d == 'L') balls.push_back(make_tuple(y, x, 0));
            if (d == 'U') balls.push_back(make_tuple(y, x, 1));
            if (d == 'R') balls.push_back(make_tuple(y, x, 2));
            if (d == 'D') balls.push_back(make_tuple(y, x, 3));
            maps[y][x] = 1;
        }
        


        for (int i = 0; i < 2 * a; i++) {
            for (int i = 0; i < balls.size(); i++) {
                int y, x, dir;
                tie(y, x, dir) = balls[i];

                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (!isinside(ny, nx)) {
                    dir = (dir + 2) % 4; 
                }
                else {
                    maps[y][x]--; 
                    x = nx;  
                    y = ny;
                    maps[y][x]++; 
                }

                balls[i] = make_tuple(y, x, dir);
            }
            remove(); 
        }

        cout << balls.size() << endl;
    }

    return 0;
}