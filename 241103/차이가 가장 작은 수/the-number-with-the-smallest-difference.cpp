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

    cin >> n >> m;

    int res = INT_MAX;

    bool exist = false;

    for (int i = 0; i < n; i++) {
        cin >> b; s.insert(b);
            set<int>::iterator it;
            it = s.upper_bound(b - m); // x보다 큰 최초의 위치를 찾습니다.
            if (it != s.begin()) {
                it--;
                res = min(res, b - *it);
                exist = true;
            }

    }
    if(exist){ cout << res << endl; }
    else { cout << -1; }
    
    return 0;
}