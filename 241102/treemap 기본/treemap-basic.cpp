#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

#define MAX_N 5001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;

int arr[4][MAX_N];

string t;


int main() {
    map<int, int> m;           // 정수를 관리할 treemap을 선언합니다. => 빈 treemap

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == "add") {
            cin >> a >> b;
            m[a] = b;
        }
        else if (t == "find") {
            cin >> a;
            if (m.find(a) != m.end()) { // key가 2이 쌍이 treemap에 있다면
                cout << m[a] << endl;  // key가 2인 value값을 출력합니다.
            }
            else {
                cout << "None" << endl;
            }
        }
        else if (t == "remove") {
            cin >> a;
            m.erase(a);
        }
        else if (t == "print_list") {
            if (m.empty()) {
                cout << "None" << endl;
            }
            else {
                map<int, int>::iterator it;
                // key 기준 오름차순으로 순회하게 되므로
                // (2, 2), (5, 6), (10, 1) 순으로 출력됩니다.
                for (it = m.begin(); it != m.end(); it++) {
                    cout << (it->second) << " ";
                }
                cout << endl;
            }
            
        }
    }


    return 0;


}