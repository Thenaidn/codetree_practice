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
vector<int> numbers;

void Print(vector<int> ans) {
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
int calc(vector<int> ans) {
    
    int tmp = 0; int tmp2 = 0;
    for (int i = 0; i < ans.size(); i++) {
        tmp += numbers[ans[i] - 1];
    }
    for (int i = 0; i < numbers.size(); i++) {
        tmp2 += numbers[i];
    }

    return abs(tmp2 - tmp - tmp);
}
void Choose(int curr_num, int previous) {
    if (curr_num == a) {
        res = min(res, calc(answer));
        //Print(answer);
        return;
    }

    for (int i = 1; i <= a * 2; i++) {
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
    
    for (int i = 0; i < a * 2; i++) {
        cin >> b;
        numbers.push_back(b);
    }
    sort(numbers.begin(), numbers.end());
    

    Choose(0, 0);
    cout << res;
    return 0;
}