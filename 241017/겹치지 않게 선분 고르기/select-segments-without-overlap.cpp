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
vector<pair<int, int>> segment;

int m = 0;
bool doSegmentsOverlap(int x1, int x2, int x3, int x4) {
    return (x1 <= x3 && x3 <= x2) || (x3 <= x1 && x1 <= x4);
}
bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}

void Print(vector<int> ans) {
    for (auto a: ans) {
        cout << a << " ";
    }
    cout << endl;
}
bool isvalid(vector<int>& answer) {
    for (int i = 0; i < answer.size(); i++) {
        for (int j = i + 1; j < answer.size(); j++) {
            int x1 = segment[answer[i]].first;
            int x2 = segment[answer[i]].second;
            int x3 = segment[answer[j]].first;
            int x4 = segment[answer[j]].second;

            if (doSegmentsOverlap(x1, x2, x3, x4)) {
                return false;
            }
        }
    }
    return true;
}

void Choose(int curr_num, vector<int>& answer) {
    if (isvalid(answer)) {
        //Print(answer);
        m = max(m, (int)answer.size());
    }
    if (curr_num == n) {
        return;
    }

    answer.push_back(curr_num);
    Choose(curr_num + 1, answer);
    answer.pop_back();
    Choose(curr_num + 1, answer);

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b >> c;
        segment.push_back(make_pair(b, c));
    }
    n = segment.size();
    Choose(0, answer);

    cout << m;
    return 0;
}