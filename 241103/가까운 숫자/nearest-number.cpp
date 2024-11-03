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


    for (int i = 0; i < n; i++) { 
        cin >> b; s.insert(b); 
        int res = INT_MAX;
        for (int i : s) {
            set<int>::iterator it; // iterator를 선언합니다. 
            it = s.upper_bound(i); // x보다 큰 최초의 위치를 찾습니다.
            if (it != s.end()) {
                res = min(res, abs(i - *it));
            }
            
        }
        cout << res << endl;
    }
    //for (int i : s) {
    //    set<int>::iterator it; // iterator를 선언합니다. 
    //    it = s.upper_bound(x); // x보다 큰 최초의 위치를 찾습니다.
    //    cout << *it << endl;   // 해당 값을 출력합니다. (10)

    //    it--;                  // 한칸 전으로 이동합니다.
    //    cout << *it << endl;   // 해당 값을 출력합니다. (6)
    //}

    
    return 0;
}