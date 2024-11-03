#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;

#define MAX_N 100001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;

int arr[4][MAX_N];

string t;



int main() {

    cin >> n >> m;

    set<pair<int, int>> s;
    set<pair<int, int>> running;
    int res = INT_MAX;

    for (int i = 0; i < n; i++) {
        int point, speed;
        cin >> point >> speed;
        s.insert({ point,speed });
    }
    bool tmp = true;
    for (int i = 1; i <= m; i++) {
        if (tmp) {
            for (auto p : s) {
                auto it = running.lower_bound({p.first + p.second, INT_MIN });

                if (it != running.end() && it->first == p.first + p.second) {
                    if (p.second < it->second) {
                        running.erase(it);
                        running.insert({ p.first + p.second, p.second });
                    }
                }
                else {
                    running.insert({ p.first + p.second, p.second });
                }
            }
            s.clear();
            tmp = false;
        }
        else {
            for (auto p : running) {
                auto it = s.lower_bound({ p.first + p.second, INT_MIN });

                if (it != s.end() && it->first == p.first + p.second) {
                    if (p.second < it->second) {
                        s.erase(it);
                        s.insert({ p.first + p.second, p.second });
                    }
                }
                else {
                    s.insert({ p.first + p.second, p.second });
                }
            }
            running.clear();
            tmp = true;
        }
        
    }

    if (!tmp) { cout << running.size(); }
    else { cout << s.size(); }
    return 0;
}