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
    set<int> s;                // 정수를 관리할 treeset을 선언합니다. => 빈 set

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == "add") {
            cin >> a;
            s.insert(a);
        }
        else if (t == "largest") {
            if (s.size() == 0) { cout << "None\n"; }
            else {
                cout << *s.rbegin() << endl;
            }
        }
        else if (t == "smallest") {
            if (s.size() == 0) { cout << "None\n"; }
            else {
                cout << *s.begin() << endl;
            }
        }
        else if (t == "lower_bound") {
            cin >> a;
            auto it = s.lower_bound(a);
            if (it == s.end()) {
                cout << "None\n";
            }
            else {
                cout << *it << endl;
            }
        }
        else if (t == "upper_bound") {
            cin >> a;
            auto it = s.upper_bound(a);
            if (it == s.end()) {
                cout << "None\n";
            }
            else {
                cout << *it << endl;
            }
        }
        else if (t == "find") {
            cin >> a;
            if (s.find(a) != s.end()) { // 숫자 9가 treeset에 d다면
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        else if (t == "remove") {
            cin >> a;
            s.erase(a);
        }
    }
    
    //if (s.find(3) != s.end()) { // 숫자 3이 set에 있다면
    //    cout << "exists!" << endl;
    //}

    //cout << *s.lower_bound(3) << endl; // 숫자 3보다 같거나 큰 최초의 숫자를 출력합니다. ==> 3
    //cout << *s.upper_bound(3) << endl; // 숫자 3보다 큰 최초의 숫자를 출력합니다. ==> 5

    //cout << *s.begin() << endl;   // 가장 작은 원소를 출력합니다. => 3
    //cout << *s.rbegin() << endl;  // 가장 큰 원소를 출력합니다. => 9

    //s.erase(9);                   // 숫자 9를 제거합니다.
    //if (s.find(9) == s.end()) { // 숫자 9가 treeset에 없다면
    //    cout << "not exists!" << endl;
    //}

    return 0;
}