#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>
using namespace std;

#define MAX_N 100001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;

int arr[4][MAX_N];

string t;

queue<int> q;
unordered_set<int> set[250001];
unordered_set<int> invited;

void bfs() {
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        for (int i = 0; i < m; i++) {
            if (set[i].find(tmp) != set[i].end()) {
                set[i].erase(tmp);

                if (set[i].size() == 1) {
                    invited.insert(*set[i].begin());
                    q.push(*set[i].begin());
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            set[i].insert(b);
        }
    }
    invited.insert(1);
    q.push(1);

    bfs();

    int res = 0;

    res = invited.size();
    cout << res;
    return 0;

}