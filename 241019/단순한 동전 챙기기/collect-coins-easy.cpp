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

int n = 0;
vector<int> answer;
int res = INT_MAX;
char maps[20][20];
int tmpmaps[20][20] = { 0, };
pair<int, int> points[10];
pair<int, int> startpoint;
pair<int, int> endpoint;
int pointon[10] = { 0 };
void Print(vector<int> ans) {
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
int calc(vector<int> ans) {
    
    int dy = abs(startpoint.first - points[ans[0]].first);
    int dx = abs(startpoint.second - points[ans[0]].second);
    int tmp = dy + dx;
    for (int i = 1; i < ans.size(); i++) {
        dy = abs(points[ans[i - 1]].first - points[ans[i]].first);
        dx = abs(points[ans[i - 1]].second - points[ans[i]].second);
        tmp += dy + dx;
    }
    dy = abs(points[ans[ans.size() - 1]].first - endpoint.first);
    dx = abs(points[ans[ans.size() - 1]].second - endpoint.second);
    tmp += dy + dx;

    return tmp;
}
void Choose(int curr_num, int previous) {
    if (curr_num == 4) {

        for (int i = 0; i < 3; i++) {
            if (pointon[answer[i]] == 0) { return; }
        }
        res = min(res, calc(answer));
        //Print(answer);
        return;
    }

    for (int i = 1; i <= a; i++) {
        if (i <= previous) { continue; }
        answer.push_back(i);
        Choose(curr_num + 1, i);
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
            if (maps[i][j] == 'S') {
                startpoint = make_pair(i, j);
            }
            else if (maps[i][j] == 'E') {
                endpoint = make_pair(i, j);
            }
            else if (maps[i][j] == '.') { continue; }
            else {
                points[maps[i][j] - '0'] = make_pair(i, j);
                pointon[maps[i][j] - '0'] = true;
                n++;
            }
        }
    }

    if (n < 3) { cout << -1; return 0; }

    Choose(1, 0);
    cout << res;
    return 0;
}