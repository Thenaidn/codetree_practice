#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
using namespace std;

int a, b, c, d, e;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int n = 2;
vector<int> answer;
int m[1001];
int num[1001] = { 0 };
vector<int> turns;
int res = 0;

void Print(vector<int> ans) {
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
int calc(vector<int> ans) {

    int score = 0;
    for (int i = 0; i < turns.size(); i++) {
        num[ans[i]] += turns[i];
    }
    for (int i = 0; i < turns.size(); i++) {
        if (num[i] >= b - 1) { score++; }
        num[i] = 0;
    }

    return score;
}
void Choose(int curr_num) {
    if (curr_num == n + 1) {

        for (int i : answer) {
            if (i >= c) { return; }
        }
        res = max(res, calc(answer));
        return;
    }

    for (int i = 0; i < a; i++) {
        answer.push_back(i);
        Choose(curr_num + 1);
        answer.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    n = a;
    for (int i = 0; i < a; i++) {
        cin >> d;
        turns.push_back(d);
    }

    Choose(1);
    cout << res;
    return 0;
}