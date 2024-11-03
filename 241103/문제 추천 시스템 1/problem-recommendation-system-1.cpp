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

    cin >> n;

    set<pair<int, int>> s;
    int res = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> c >> b;
        s.insert({ b,c });
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == "rc") {
            cin >> b;
            if (b == 1) {
                auto a = *s.rbegin();
                cout << a.second << endl;
            }
            if (b == -1) {
                auto a = *s.begin();
                cout << a.second << endl;
            }
        }
        else if (t == "ad") {
            cin >> c >> b;
            s.insert({ b,c });
        }
        else if (t == "sv") {
            cin >> c >> b;
            s.erase({ b,c });
        }
    }



    return 0;
}