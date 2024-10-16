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
    int min1 = min(x1, x2);
    int max1 = max(x1, x2);
    int min2 = min(x3, x4);
    int max2 = max(x3, x4);

    return !(max1 < min2 || max2 < min1);
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
int countoverlap(vector<int> answer) {

    int tmp = 0;
    if (answer.size() == 1) { return 1; }
    for (int i = 0; i < answer.size(); i++) {
        for (int j = i + 1; j < answer.size(); j++) {

            int x1 = segment[answer[i]].second;
            int x2 = segment[answer[i]].first;
            int x3 = segment[answer[j]].second;
            int x4 = segment[answer[j]].first;
            if (!doSegmentsOverlap(x1, x2, x3, x4)) { tmp++; }
        }
    }

    return tmp;
}

void Choose(int curr_num) {
    if (!answer.empty()) {
        //Print(answer);
        m = max(m, countoverlap(answer));
        if (curr_num == n + 1) {
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        answer.push_back(i);
        Choose(curr_num + 1);
        answer.pop_back();
    }

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

    Choose(1);

    cout << m;
    return 0;
}