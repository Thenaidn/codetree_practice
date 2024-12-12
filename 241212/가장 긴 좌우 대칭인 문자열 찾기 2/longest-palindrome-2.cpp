#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input_str;
    cin >> input_str;  // 입력 문자열 받기
    
    // Manacher's 알고리즘을 적용하기 위해 문자열 사이사이에 #을 넣습니다.
    string modified_str = "#";
    for (char c : input_str) {
        modified_str += c;
        modified_str += "#";
    }
    
    int n = modified_str.size();
    int r = -1, p = -1;  // r: 오른쪽 끝, p: 가장 우측에 있는 팰린드롬 중심
    int A[n];  // A[i]: i번을 중심으로 한 팰린드롬의 반지름

    // Manacher's 알고리즘
    for (int i = 0; i < n; i++) {
        // i가 r보다 크면, 팰린드롬 길이는 0부터 시작
        if (r < i) {
            A[i] = 0;
        }
        // r보다 작으면, 대칭되는 위치의 A값을 이용
        else {
            int ii = 2 * p - i;  // i의 대칭 위치
            A[i] = min(r - i, A[ii]);
        }

        // i를 중심으로 최대한 팰린드롬을 확장
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < n && modified_str[i - A[i] - 1] == modified_str[i + A[i] + 1]) {
            A[i]++;
        }

        // 팰린드롬 확장 후, r과 p 갱신
        if (i + A[i] > r) {
            r = i + A[i];
            p = i;
        }
    }

    // 가장 긴 팰린드롬의 길이를 구하기
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        max_len = max(max_len, A[i]);
    }

    // 구한 길이는 #을 포함한 길이이므로, 이를 제외하고 실제 길이를 계산
    cout << max_len << endl;

    return 0;
}
