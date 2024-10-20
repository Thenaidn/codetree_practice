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
    return y >= 0 && y < a && x >= 0 && x < b;
}

int cnt = 0;
void dfs(int y, int x, int k) {

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isinside(ny, nx)) {
            if (maps[ny][nx] > k && visited[ny][nx] == false) {
                visited[ny][nx] = true;
                dfs(ny, nx, k);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    int max_num = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> maps[i][j];
            max_num = max(max_num, maps[i][j]);
        }
    }
    for (int k = 1; k <= max_num; k++) {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (!visited[i][j] && maps[i][j] > k) {
                    dfs(i, j, k);
                    res++;
                }
            }
        }
        answer.push_back(res);
        res = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                visited[i][j] = false;
            }
        }
    }
    int ans = 0;
    int ansnum = max_num;
    for (int k = max_num; k >= 1; k--) {
        if (ans <= answer[k - 1]) {
            ans = answer[k - 1];
            ansnum = k;
        }
        
    }
    
    cout << ansnum << " " << ans;

    return 0;
}