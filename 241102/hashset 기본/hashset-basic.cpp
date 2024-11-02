#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

#define MAX_N 5001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;

int arr[4][MAX_N];

string t;


int main() {
    unordered_set<int> s;      // 정수를 관리할 hashset을 선언합니다. => 빈 set
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> a;
        if (t == "find") {
            if (s.find(a) != s.end()) { // 숫자 3이 set에 있다면
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        if (t == "add") {
            s.insert(a);
        }
        if (t == "remove") {
            s.erase(a);
        }
    }

    return 0;

}