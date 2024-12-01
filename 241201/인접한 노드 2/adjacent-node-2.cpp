#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int n = 10008;

vector<int> edges[n + 1];
bool visited[n + 1];

int parent[n + 1];

int start_points[n] = { -1, 1, 1, 1, 2, 2, 2, 4 };
int end_points[n] = { -1, 4, 7, 6, 6, 3, 5, 8 };
int arr[n + 1] = { 0, 6, 10, 3, 3, 4, 2, 6, 2 };

int dp[n + 1][2];

vector<int> selected[2];

void DFS(int x, int num) {
    if(num == 1){selected[0].push_back(x);}
    else{selected[1].push_back(x);}
    for (int i = 0; i < (int)edges[x].size(); i++) {
        int y = edges[x][i];
        if (!visited[y]) {
            visited[y] = true;
            parent[y] = x;

            if(num==1){DFS(y, 0);}
            else{DFS(y, 1);}
        }
    }
    dp[x][0] = 0; // 색칠하지 않는 경우에 대한 초기값입니다.
    dp[x][1] = arr[x]; // 색칠하는 경우에 대한 초기값입니다.
    for (int i = 0; i < (int)edges[x].size(); i++) {
        int y = edges[x][i];
        if (parent[y] != x)
            continue;
        dp[x][0] += max(dp[y][0], dp[y][1]);
        dp[x][1] += dp[y][0];
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) { cin >> arr[i]; }
    for (int i = 1; i <= n - 1; i++) {
        int x; int y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    visited[start_points[1]] = true;
    DFS(start_points[1], 0);
    if(dp[start_points[1]][0] > dp[start_points[1]][1]){
        cout << dp[start_points[1]][0] << endl;
        sort(selected[0].begin(), selected[0].end());
        for(int i: selected[0]){cout << i <<  " ";}
    }
    else{
        cout << dp[start_points[1]][1] << endl;
        sort(selected[1].begin(), selected[1].end());
        for(int i: selected[1]){cout << i <<  " ";}
    }
    // dp[1][0], dp[1][1] 중 최댓값을 출력합니다.
   // cout << max(dp[start_points[1]][0], dp[start_points[1]][1]);
    return 0;
}
