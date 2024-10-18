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

int maps[11];

int res = 1110;


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

void Choose(int x, int count) {
    if (x >= a - 1) { 
        res = min(res, count);
        return;
    }

    for (int i = 1; i <= maps[x]; i++) {
        int nx = x + i;
        if (nx < a) { 
            Choose(nx, count + 1);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;

    for (int i = 0; i < a; i++) {
        cin >> maps[i];
    }



    Choose(0, 0);
    if (res == 1110) { cout << -1; return 0; }
    cout << res;
    return 0;
}