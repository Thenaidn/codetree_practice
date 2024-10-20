#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int a, b, c, d, e;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool visited[1001][1001] = {false};
int order = 1;
int n = 0;
vector<int> answer;
int res = 0;
int maps[1001][1001];
int tmpmaps[20][20] = { 0, };
vector<pair<int, int>> points;
bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}

int cnt = 0;
void dfs(int y, int x) {

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isinside(ny, nx)) {
            if (maps[ny][nx] == 1 && visited[ny][nx] == false) {
                visited[ny][nx] = true;
                cnt++;
                dfs(ny, nx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (maps[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                res++;
                answer.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(answer.begin(), answer.end());
    
    cout << res << endl;
    for (int i : answer) {
        if (i == 0) { i++; }
        cout << i << "\n";
    }
    return 0;
}