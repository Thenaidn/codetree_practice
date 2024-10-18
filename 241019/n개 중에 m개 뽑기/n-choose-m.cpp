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
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
bool used[1000] = { false };
void Choose(int curr_num) {
    if (curr_num == n + 1) {
        Print(answer);
        return;
    }

    for (int i = 1; i <= a; i++) {
        answer.push_back(i);
        if(!used[i]){ used[i] = true; }
        else { answer.pop_back(); return; }
        Choose(curr_num + 1);
        answer.pop_back();
        used[i] = false;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> n;

    Choose(1);
    return 0;
}