#include <iostream>
#include <algorithm>

using namespace std;

// 변수 선언
long long n, k;

int main() {
    // 입력:
    cin >> n;
    cin >> k;
    
    long long lo = 1;                        // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    long long hi = n * n;                    // 답이 될 수 있는 가장 큰 숫자 값을 설정합니다.
    long long ans = n * n;                   // 답을 저장합니다.
    
    while(lo <= hi) {                        // [lo, hi]가 유효한 구간이면 계속 수행합니다.
        long long mid = (lo + hi) / 2;       // 가운데 위치를 선택합니다.
        
        long long val = 0;
        for(int i = 1; i <= n; i++)
            val += min(n, mid / i);
        
        if(val >= k) {                       // 결정문제에 대한 답이 Yes라면
            hi = mid - 1;                    // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 hi를 바꿔줍니다.
            ans = min(ans, mid);             // 답의 후보들 중 최솟값을 계속 갱신해줍니다.
        }
        else lo = mid + 1;                   // 결정문제에 대한 답이 No라면 lo를 바꿔줍니다.
    }
    
    // 정답을 출력합니다.
    cout << ans;
    return 0;
}