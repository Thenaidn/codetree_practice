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
    for (int a : ans) {
        cout << a + 3 << "";
    }
    cout << endl;
}
bool completed = false;

bool calc(int length) {
    for (int i = 1; i <= length / 2; i++) {
        bool same = true;
        if (length - 2 * i < 0) {
            continue;
        }
        for (int j = 0; j < i; j++) {
            if (answer[length - i + j] != answer[length - 2 * i + j]) {
                same = false;
                break;
            }
        }
        if (same) return false;
    }
    return true;
}

bool Choose(int curr_num) {

    if (curr_num == n + 1) {
        Print(answer);
        return true;
    }

    for (int i = 1; i <= a; i++) {
        answer.push_back(i);
        if (calc(curr_num)) {
            if (Choose(curr_num + 1)) {
                return true;
            }
        }

        answer.pop_back();
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a = 3;

    Choose(1);
    return 0;
}