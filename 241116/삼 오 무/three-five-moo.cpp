#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n;

    cin >> n;

    long long left = 1;                          // 가장 작은 숫자 값을 설정합니다.
    long long right = 9223372036854775807;                        // 가장 큰 숫자 값을 설정합니다.
    long long min_num = 0;                      // 최소이므로, 답이 될 수 있는 값보다 더 큰 값으로 설정합니다.
    while (left <= right) {                // [left, right]가 유효한 구간이면 계속 수행합니다.
        long long mid = (left + right) / 2;      // 가운데 위치를 선택합니다.
        long long tmp = mid - (mid / 3) - (mid / 5) + (mid / 15);
        if(tmp == n){
            mid-=1;
            if(mid - (mid / 3) - (mid / 5) + (mid / 15) != n){mid++;}
            cout << mid; 
            return 0;}
        if(tmp > n){right = mid - 1;}
        else{left = mid+1;}
    }

    //cout << min_num;                       // 조건을 만족하는 최소 n 값을 출력합니다.
    return 0;
}
