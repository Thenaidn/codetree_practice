#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
using namespace std;

int a, b, c, d, e;
int dy[12] = { 1, 2, -1, -2, 0,0,1,-1 , 1,-1,1,-1 };
int dx[12] = { 0, 0, 0, 0, 1, -1, 0, 0 ,1,-1,-1,1 };
int maps[21][21] = { 0, };





int n = 2;
vector<int> answer;
vector<pair<int, int>> bomb_loc;

int m = 0;

bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}

void Print(vector<int> ans) {
    for (auto a: ans) {
        cout << a << " ";
    }
    cout << endl;
}
int calc(vector<int> ans) {
    for (int i = 0; i < n; i++) {
        int y = bomb_loc[i].first;
        int x = bomb_loc[i].second;
        int bomb = ans[i];
        for (int j = 0; j < 4; j++) {
            int ny = y + dy[(bomb - 1) * 4 + j];
            int nx = x + dx[(bomb - 1) * 4 + j];
            if (isinside(ny, nx)) {
                maps[ny][nx]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (maps[i][j] > 0) {
                cnt++;
                maps[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int y = bomb_loc[i].first;
        int x = bomb_loc[i].second;
        maps[y][x] = 1;
    }
    return cnt;
}
void Choose(int curr_num) {
    if (curr_num == n + 1) {
        m = max(m, calc(answer));
        return;
    }

    for (int i = 1; i <= 3; i++) {
        answer.push_back(i);
        Choose(curr_num + 1);
        answer.pop_back();
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 1) {
                bomb_loc.push_back(make_pair(i, j));
            }
        }
    }
    n = bomb_loc.size();

    Choose(1);

    cout << m;
    return 0;
}