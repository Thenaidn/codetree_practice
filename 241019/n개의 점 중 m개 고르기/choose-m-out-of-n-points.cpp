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
vector<pair<int, int>> points;

void Print(vector<int> ans) {
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
int calc(vector<int> ans) {

    int tmp = points[ans[0]].first - points[ans[1]].first;
    int tmp2 = points[ans[0]].second - points[ans[1]].second;
    

    return tmp * tmp + tmp2 * tmp2;
}
void Choose(int curr_num, int previous) {
    if (curr_num == 2) {

        res = min(res, calc(answer));
        //Print(answer);
        return;
    }

    for (int i = 0; i < a; i++) {
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
    
    cin >> a >> b;
    
    for (int i = 0; i < a; i++) {
        cin >> c >> d;
        points.push_back(make_pair(c, d));
    }

    Choose(0, -1);
    cout << res;
    return 0;
}