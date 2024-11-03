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
    cin >> n;

    int res;
    for (int i = 0; i < n; i++) { 
        cin >> b; s.insert(b); 
        if (i == 0) { res = b; cout << res << endl; }
        else {
            set<int>::iterator it;
            it = s.upper_bound(b); // x보다 큰 최초의 위치를 찾습니다.
            if (it != s.end()) {
                res = min(res, abs(b - *it));
            }
            cout << res << endl;
        }
        
    }



    
    return 0;
}