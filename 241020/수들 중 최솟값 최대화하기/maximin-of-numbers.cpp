#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int a, b, c, d, e;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

bool visited[1000] = { false };

int n = 0;
vector<int> answer;
int res = INT_MIN;
int maps[20][20];
int tmpmaps[20][20] = { 0, };
vector<pair<int, int>> points;

void Print(vector<int> ans) {
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
int calc(vector<int>& ans) {
    int m = INT_MAX;
    for (int i = 0; i < a; i++) {
        m = min(m,maps[i][answer[i]]);
    }
    return m;
}
void Choose(int curr_num) {
    if (curr_num == a) {
        res = max(res, calc(answer));
        //Print(answer);
        return;
    }

    for (int i = 0; i < a; i++) {
        if (!visited[i]) {
            visited[i] = true;
            answer.push_back(i);
            Choose(curr_num + 1);
            answer.pop_back();
            visited[i] = false;
        }
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
        }
    }


    Choose(0);
    cout << res;
    return 0;
}