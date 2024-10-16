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
    for (auto a: ans) {
        cout << a << " ";
    }
    cout << endl;
}
int res = 0;
void Choose(int curr_num, int stack, int previous, bool b) {
    if (curr_num == n + 1) {
        if (b) {
            
            res++;
            //Print(answer); 
        }
        return;
    }

    for (int i = 1; i <= 4; i++) {
        if (previous == 0) {
            answer.push_back(i);
            if(i == 1){ Choose(curr_num + 1, 0, 0, true); }
            else { Choose(curr_num + 1, 1, i, false); }
            answer.pop_back();
        }
        else if (previous == i && stack < i) {
            answer.push_back(i);
            if(stack + 1 == i){ Choose(curr_num + 1, 0, 0, true); }
            else { Choose(curr_num + 1, stack + 1, i, false); }
            answer.pop_back();
        }
        else if (previous == i && stack >= i) {
            answer.push_back(i);
            Choose(curr_num + 1, 0, 0, true);
            answer.pop_back();
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    Choose(1, 0, 0, false);
    cout << res;
    return 0;
}