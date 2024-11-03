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
    set<int> s;
    for (int i = 1; i <= m; i++) { s.insert(i); }

    for (int i = 0; i < n; i++) {
        cin >> a;
        s.erase(a);

        cout << *s.rbegin() << " \n"; // 최댓값을 출력해줍니다.
    }
    return 0;
}