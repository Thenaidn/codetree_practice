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
    for (int i = 0; i < n; i++) {
        set<int> s; cin >> b;
        for (int j = 0; j < b; j++) {
            cin >> t;
            if (t == "I") {
                cin >> a;
                s.insert(a);
            }
            else if (t == "D") {
                cin >> a;
                if (!s.empty()) {
                    if (a == 1) {
                        s.erase(*s.rbegin());
                    }
                    if (a == -1) {
                        s.erase(*s.begin());
                    }
                }
            }
        }
        
        if (s.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *s.rbegin() << " " << *s.begin() << endl;
        }
    }
    


    return 0;
}