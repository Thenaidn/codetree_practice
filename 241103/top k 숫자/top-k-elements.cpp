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
    set<int> s;

    s.insert(0);
    cin >> n >> m;

    int res;
    for (int i = 0; i < n; i++) { 
        cin >> b; s.insert(b); 
    }
    set<int>::iterator it;
    it = s.upper_bound(*s.rbegin() - 1);
    for (int i = 0; i < m; i++) {
        cout << *it << " ";
        it--;
    }


    
    return 0;
}