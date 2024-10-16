#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int a, b, c, d;
int dy[12] = { 1, 2, -1, -2, 0,0,1,-1 , 1,-1,1,-1 };
int dx[12] = { 0, 0, 0, 0, 1, -1, 0, 0 ,1,-1,-1,1 };
int maps[21][21] = { 0, };


string e;


int n = 0;
vector<int> answer;
vector<pair<int, int>> segment;
vector<char> chars;
int m = INT_MIN;

bool isinside(int y, int x) {
    return y >= 0 && y < a && x >= 0 && x < a;
}

void Print(vector<int> ans) {
    for (auto a: ans) {
        cout << a << " ";
    }
    cout << endl;
}
int Calc(vector<int> ans) {
    
    int a = 0;
    int b = 0;
    char next = ' ';
    for (int i = 0; i < e.size(); i++) {
        
        if (e[i] >= 'a' && e[i] <= 'z') {
            for (int j = 0; j < chars.size(); j++) {
                if (e[i] == chars[j]) {
                    b = ans[j];
                }
            }
            if (next != ' ') {
                if (next == '+') { b = a + b; }
                if (next == '-') { b = a - b; }
                if (next == '*') { b = a * b; }
                next = ' ';
            }
        }
        else {
            next = e[i];
        }
        a = b;
    }

    return a;
}

void Choose(int curr_num) {
    if (curr_num == n + 1) {
        m = max(m,Calc(answer));
        return;
    }

    for (int i = 1; i <= 4; i++) {
        answer.push_back(i);
        Choose(curr_num + 1);
        answer.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt[200] = { 0, };
    
    cin >> e;
    for (int i = 0; i < e.size(); i++) {
        if (e[i] >= 'a' && e[i] <= 'z') {
            cnt[e[i]]++;
            if (cnt[e[i]] == 1) {
                chars.push_back(e[i]);
                n++;
            }
        }
    }
    Choose(1);

    cout << m;
    return 0;
}