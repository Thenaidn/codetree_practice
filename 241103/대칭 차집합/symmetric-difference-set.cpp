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

unordered_set<int> aa;
unordered_set<int> bb;
unordered_set<int> amb;
unordered_set<int> bma;
unordered_set<int> ans;



int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a;
        aa.insert(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> b;
        bb.insert(b);
    }
    for (int i : aa) {
        if (bb.find(i) == bb.end()) {
            amb.insert(i);
        }
    }
    for (int i : bb) {
        if (aa.find(i) == aa.end()) {
            bma.insert(i);
        }
    }

    for (int i : amb) {
        ans.insert(i);
    }
    for (int i : bma) {
        ans.insert(i);
    }

   

    int res = 0;

    res = ans.size();
    cout << res;
    return 0;

}