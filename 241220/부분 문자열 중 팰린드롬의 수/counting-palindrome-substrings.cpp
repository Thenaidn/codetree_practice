#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input_str;
    cin >> input_str;

    // Manacher's 알고리즘을 적용하기 위해 문자열을 변환
    string modified_str = "#";
    for (char c : input_str) {
        modified_str += c;
        modified_str += "#";
    }

    int n = modified_str.size();
    vector<int> A(n, 0);
    int r = -1, p = -1; // r: 오른쪽 끝, p: 중심
    long long cnt = 0; // 팰린드롬의 개수를 저장 (long long 사용)

    // Manacher's 알고리즘
    for (int i = 0; i < n; i++) {
        // 초기화
        if (i <= r) {
            A[i] = min(A[2 * p - i], r - i);
        } else {
            A[i] = 0;
        }

        // 팰린드롬 확장
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < n && modified_str[i - A[i] - 1] == modified_str[i + A[i] + 1]) {
            A[i]++;
        }

        // r과 p 갱신
        if (i + A[i] > r) {
            r = i + A[i];
            p = i;
        }

        // 팰린드롬 개수 추가
        cnt += (A[i] + 1) / 2; // # 제외한 실제 팰린드롬 개수 계산
    }

    cout << cnt << endl; // 결과 출력
    return 0;
}
