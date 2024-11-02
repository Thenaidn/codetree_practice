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
    map<string, int> m;           // 정수를 관리할 treemap을 선언합니다. => 빈 treemap

    cin >> n;
    // 각 단어가 주어진 횟수를 이미 알고 있다고 가정
    for (int i = 0; i < n; i++) {
        cin >> t;
        m[t]++;
    }

    // Iterator를 이용한 map 컨테이너 내의 원소들 순회
    // key에 해당하는 문자열이 사전순으로 앞선 쌍 부터 조회! (apple, banana, helloworld 순)
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        double rate = (it->second) * 100 / n;
        cout << (it->first);
        printf(" %.4lf\n", rate);
    }

    return 0;


}