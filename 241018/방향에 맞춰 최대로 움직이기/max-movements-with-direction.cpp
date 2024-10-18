#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
using namespace std;

int a, b, c, d, e;
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int n = 2;
vector<int> answer;
int grid[4][4];
int dirs[4][4];


int res = 0;


bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}
void Print(vector<int> ans) {
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
int calc(vector<int> ans) {

    int score = 0;
    

    return score;
}
void Choose(int y, int x, int count) {
    int nx = x; int ny = y;

    for (int i = 1; isinside(ny, nx); i++) {
        nx = x + dx[dirs[y][x] - 1] * i;
        ny = y + dy[dirs[y][x] - 1] * i;
        if (grid[ny][nx] > grid[y][x] && isinside(ny, nx)) {
            Choose(ny, nx, count + 1);
        }

    }


    res = max(res, count);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> dirs[i][j];
        }
    }
    cin >> b >> c;


    Choose(b - 1, c - 1, 0);
    cout << res;
    return 0;
}