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
int res = INT_MAX;
char maps[20][20];
int tmpmaps[20][20] = { 0, };
vector<pair<int, int>> points;

void Print(vector<int> ans) {
    for (int a : ans) {
        cout << a + 1 << " ";
    }
    cout << endl;
}
int calc(vector<int>& ans) {
    int max_dist = 0;
    for (int i = 0; i < b; i++) {
        for (int j = i + 1; j < b; j++) {
            int dx = points[ans[i]].first - points[ans[j]].first;
            int dy = points[ans[i]].second - points[ans[j]].second;
            max_dist = max(max_dist, dx * dx + dy * dy);
        }
    }
    return max_dist;
}
void Choose(int curr_num) {
    if (curr_num == a) {

        Print(answer);
        return;
    }

    for (int i = 0; i < a; i++) {
        if (!visited[i]) {
            answer.push_back(i);
            visited[i] = true;
        }
        else { continue; }
        Choose(curr_num + 1);

        answer.pop_back();
        visited[i] = false;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;


    Choose(0);
    
    return 0;
}