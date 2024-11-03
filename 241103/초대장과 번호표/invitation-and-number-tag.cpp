#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

#define MAX_N 100001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;

int arr[4][MAX_N];

string t;

vector<int> groups[250001];


int main() {
    cin >> n >> m;

    unordered_set<int> set;
    for (int i = 0; i < m; i++) {
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            if (j == 0) { set.insert(b); }
            groups[i].push_back(b);
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        int count = 1;
        for (int j = 1; j < groups[i].size(); j++) {
            if (set.find(groups[i][j]) != set.end()) {
                count++;
            }
            
        }
        if (count == groups[i].size() - 1) {
            for (int j = 1; j < groups[i].size(); j++) {
                set.insert(groups[i][j]);
            }
        }
    }
    int res = 0;

    for (int i = 0; i < m; i++) {
        int count = 1;
        for (int j = 1; j < groups[i].size(); j++) {
            if (set.find(groups[i][j]) != set.end()) {
                count++;
            }

        }
        if (count == groups[i].size() - 1) {
            for (int j = 1; j < groups[i].size(); j++) {
                set.insert(groups[i][j]);
            }
        }
    }

    res = set.size();
    cout << res;
    return 0;

}