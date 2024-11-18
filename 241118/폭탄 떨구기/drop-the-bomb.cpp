#include <iostream>
#include <algorithm>

#define MAX_N 50000

using namespace std;

// 변수 선언
int n, k;
int pos[MAX_N];
 
bool IsPossible(int mid) {
    int cnt = 1;
    int idx = 0;            // 모든 점을 제거하기 위해 몇개의 폭탄이 필요한지 확인합니다.
    for(int i = 0; i < n; i++) {
        if(pos[i] - pos[idx] <= 2 * mid) continue;
        else {
            cnt++;
            idx = i;
        }
    }

    return cnt <= k;
}

int main() {
    // 입력:
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> pos[i];

    sort(pos, pos + n);

    int lo = 0;                         // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    int hi = 1e9;                       // 답이 될 수 있는 가장 큰 숫자 값을 설정합니다.
    int ans = 1e9;                      // 답을 저장합니다.

    while(lo <= hi) {                   // [lo, hi]가 유효한 구간이면 계속 수행합니다.
        int mid = (lo + hi) / 2;        // 가운데 위치를 선택합니다.
        if(IsPossible(mid)) {           // 결정문제에 대한 답이 Yes라면
            hi = mid - 1;               // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            ans = min(ans, mid);        // 답의 후보들 중 최솟값을 계속 갱신해줍니다.
        }
        else
            lo = mid + 1;               // 결정문제에 대한 답이 No라면 right를 바꿔줍니다.
    }
    
    // 정답을 출력합니다.
    cout << ans;
    return 0;
}