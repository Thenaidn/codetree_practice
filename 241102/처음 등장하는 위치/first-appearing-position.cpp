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
    vector<long long> v;

    map<long long, long long> m;           // 정수를 관리할 treemap을 선언합니다. => 빈 treemap

    cin >> n;

    long long tmp;
    // 각 단어가 주어진 횟수를 이미 알고 있다고 가정
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (m.find(tmp) == m.end()) {
            m[tmp] = i;
        }
    }

    map<long long, long long>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << (it->first) << " " << (it->second) << endl;
    }

    return 0;


}