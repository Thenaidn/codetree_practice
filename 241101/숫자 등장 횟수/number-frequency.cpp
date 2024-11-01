#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

#define MAX_N 10001
#define MOD 1000000007


int a, b, c, d, e;

int arr[MAX_N];

int main() {
    unordered_map<int, int> m; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap

    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        cin >> arr[i];
        if (m.find(arr[i]) != m.end()) {
            int tmp = m[arr[i]];
            m.erase(arr[i]);
            m[arr[i]] = tmp + 1;
        }
        else {
            m[arr[i]] = 1;
        }
    }
    for (int i = 0; i < b; i++) {
        cin >> c;
        if (m.find(c) != m.end()) {
            cout << m[c] << " ";
        }
        else {
            cout << 0 << " ";
        }
    }

    return 0;


}