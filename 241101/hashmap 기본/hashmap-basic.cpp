#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

#define MAX_N 1001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;
int treasure[MAX_N][101];
int dp[MAX_N][MAX_N];

int alen; int blen;

int main() {
    unordered_map<int, int> m; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap
    cin >> n;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            cin >> a >> b;
            if (m.find(a) != m.end()) {
                m.erase(a);
            }
            m.insert({ a, b });
        }
        else if (cmd == "find") {
            cin >> a;
            if (m.find(a) != m.end()) {
                cout << m[a] << endl;
            }
            else {
                cout << "None" << endl;
            }
        }
        else if (cmd == "remove") {
            cin >> a;
            m.erase(a);
        }
    }

    return 0;
}