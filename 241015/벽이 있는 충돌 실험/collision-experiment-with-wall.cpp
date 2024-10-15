#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <cmath>
using namespace std;



int a, b, c, d, e;
int maps[1111][1111] = { 0 };
int balls[1111][1111] = { 0 };
int dirs[1111][1111] = { 11, };
int tmp[1111][1111] = { 0, };
int tmpdirs[1111][1111] = { 11, };
int dy[8] = { 0, 0, -1, 1,1,-1,1,-1 };
int dx[8] = { -1, 1, 0, 0,-1,1,1,-1 };
int res = 0;



bool isinside(int y, int x) {
    return x >= 0 && x < a && y >= 0 && y < a;
}


int cnt = 1;

void move(int y, int x, int dir) {
    int nx, ny;
    nx = x + dx[dir];
    ny = y + dy[dir];

    if (!isinside(ny, nx)) {
        tmp[y][x]++;
        if (dirs[y][x] == 0) { tmpdirs[y][x] = 1; }
        else if (dirs[y][x] == 1) { tmpdirs[y][x] = 0; }
        else if (dirs[y][x] == 2) { tmpdirs[y][x] = 3; }
        else if (dirs[y][x] == 3) { tmpdirs[y][x] = 2; }
    }
    else {
        tmp[ny][nx]++;
        tmpdirs[ny][nx] = dir;
    }
    

}

void turn() {

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (balls[i][j] == 1) {
                move(i, j, dirs[i][j]);
            }
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (tmp[i][j] > 1) {
                tmp[i][j] = 0;
                tmpdirs[i][j] = 11;
            }
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            balls[i][j] = tmp[i][j];
            dirs[i][j] = tmpdirs[i][j];
            tmp[i][j] = 0;
            tmpdirs[i][j] = 11;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {

        

        cin >> a >> b;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                //cin >> maps[i][j];
                maps[i][j] = 0;
            }
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                tmpdirs[i][j] = 11;
                dirs[i][j] = tmpdirs[i][j];

            }
        }
        for (int i = 0; i < b; i++) {
            char dir;
            cin >> c >> d >> dir;
            c--; d--;
            balls[c][d] = 1;
            if (dir == 'L') {
                dirs[c][d] = 0;
            }
            else if (dir == 'R') {
                dirs[c][d] = 1;
            }
            else if (dir == 'U') {
                dirs[c][d] = 2;
            }
            else if (dir == 'D') {
                dirs[c][d] = 3;
            }
        }

        for (int i = 0; i < 4 * a * a; i++) {
            turn();
        }

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                if (dirs[i][j] != 11) {
                    {
                        res++;
                    }
                }
            }


        }
        cout << res << endl;
        res = 0;
    }
    return 0;
}