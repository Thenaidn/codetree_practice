#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N 300000

using namespace std;

// 변수 선언
string temp;  // 입력 문자열
string input_str = "";
int n;

// A : i번지를 중심으로 하는 홀수 길이의 팰린드롬 중 
//     가장 긴 팰린드롬의 반지름의 길이
int A[MAX_N];

int main() {
    char exclude;
    cin >> n >> exclude >> temp;
    // 입력 문자열 받기

    // Manacher's algorithm을 적용하기 위해
    // 주어진 문자열 내 문자 사이사이에 #을 넣어줍니다.    
    for (char c : temp) {
        input_str += "#";
        input_str += c;
    }
    input_str += "#";

    // Manacher's algorithm을 진행해봅니다.
    n = (int)input_str.size();
    int r = -1, p = -1;
    int max_len = 0, center = 0;  // 가장 긴 팰린드롬 길이와 중심 인덱스

    for (int i = 0; i < n; i++) {
        // 초기값 설정
        if (r < i)
            A[i] = 0;
        else {
            int ii = 2 * p - i;
            A[i] = min(r - i, A[ii]);
        }

        // i를 중심으로 최대로 확장
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < n &&
            input_str[i - A[i] - 1] == input_str[i + A[i] + 1]
            && input_str[i - A[i] - 1] != exclude && input_str[i + A[i] + 1] != exclude)
            A[i]++;

        // r과 p 갱신
        if (i + A[i] > r) {
            r = i + A[i];
            p = i;
        }

        // 가장 긴 팰린드롬 갱신
        if (A[i] > max_len) {
            max_len = A[i];
            center = i;
        }
    }



    cout << max_len << endl;
    return 0;
}
