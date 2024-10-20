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
            if (maps[ny][nx] == k && visited[ny][nx] == false) {
                visited[ny][nx] = true;
                cnt++;
                dfs(ny, nx, k);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    b = a;
    int maxnum = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> maps[i][j];
            maxnum = max(maxnum, maps[i][j]);
        }
    }
    for (int k = 1; k <= maxnum; k++) {
        bool completed = false;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (!visited[i][j] && maps[i][j] == k) {
                    dfs(i, j, k);
                    if (cnt > 3) { 
                        if(completed){ res++; }
                        completed = true;
                    }
                    answer.push_back(cnt);
                    cnt = 0;
                }
            }
        }

    }
    int ans = 0;
    for (int k = 0; k< answer.size(); k++) {
        ans = max(ans, answer[k]);
    }
    
    cout << res << " " << ans;

    return 0;
}