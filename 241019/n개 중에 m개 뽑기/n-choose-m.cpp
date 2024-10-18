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

void Print(vector<int> ans) {
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
void Choose(int curr_num, int previous) {
    if (curr_num == n + 1) {

        Print(answer);
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

    cin >> a >> n;

    Choose(1, 0);
    return 0;
}