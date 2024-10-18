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
void Choose(int curr_num) {
    if (completed) { return; }
    if (curr_num == n + 1) {

        bool cmp = true;
        if (n >= 2) {
            for (int i = 0; i < n - 1; i++) {
                if (answer[i] == answer[i + 1]) { cmp = false; break; }
            }
        }
        if (n >= 4) {
            int count = 0;
            for (int i = 0; i < n - 2; i++) {
                if (answer[i] == answer[i + 2]) { 
                    count++;
                    if(count == 2){ cmp = false; break; }
                }
                else {
                    count = 0;
                }
            }
        }
        if (n >= 6) {
            int count = 0;
            for (int i = 0; i < n - 3; i++) {
                if (answer[i] == answer[i + 3]) {
                    count++;
                    if (count == 3) { cmp = false; break; }
                }
                else {
                    count = 0;
                }
            }
        }



        
        if (cmp) { Print(answer); completed = true; }
        return;
    }

    for (int i = 1; i <= a; i++) {
        answer.push_back(i);
        Choose(curr_num + 1);
        answer.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a = 3;

    Choose(1);
    return 0;
}