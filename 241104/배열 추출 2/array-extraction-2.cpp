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


string t;

vector<int> v;
int main() {
    float res = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> plus;
    priority_queue<int> minus;

    for (int i = 0; i < n; i++) {
        cin >> a;

        if (a != 0) {
            if (a > 0) {
                plus.push(a);
            }
            else {
                minus.push(a);
            }
        }
        else {
            if (plus.size() == 0 && minus.size() == 0) {
                cout << 0 << endl;
            }
            else {
                if (plus.size() > 0) {
                    if (minus.size() > 0) {
                        if (abs(plus.top()) >= abs(minus.top())) {
                            cout << minus.top() << endl;
                            minus.pop();
                        }
                        else {
                            cout << plus.top() << endl;
                            plus.pop();
                        }
                    }
                    else {
                        cout << plus.top() << endl;
                        plus.pop();
                    }
                }
                else { 
                    cout << minus.top() << endl;
                    minus.pop();
                }
            }
        }

    }


    //printf("%.2f", res);

    return 0;
}