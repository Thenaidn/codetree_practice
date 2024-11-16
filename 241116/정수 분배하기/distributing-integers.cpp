#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n,m;
int arr[100000] = {0,};

// max_sum을 최대 합으로 했을 때
// 칸막이 수 4개 이내로 해결이 가능한지 판단합니다.
bool IsPossible(int p_num) {
    
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        int leftover = arr[i];
        while(leftover>=p_num){
            leftover-=p_num;
            count++;
        }
    }

    
    return count>= m;
}

int main() {

    cin >> n>>m;
    long long sum=0;
    for(int i=0;i<n;i++){cin>>arr[i]; sum+=arr[i];}
    int left = 1;                          // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    int right = sum / n;                        // 답이 될 수 있는  가장 큰 숫자 값을 설정합니다.
    int ans = INT_MIN;                     // 최소이므로, 초기값을 INT_MAX로 설정합니다.
    
    while (left <= right) {                // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2;      // 가운데 위치를 선택합니다.
        if(IsPossible(mid)) {              // 결정문제에 대한 답이 Yes라면
            left = mid + 1;               // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            ans = max(ans, mid);           // 답의 후보들 중 최솟값을 계속 갱신해줍니다.
        }
        else                               
            right = mid - 1;                // 결정문제에 대한 답이 No라면 left를 바꿔줍니다.
    }

    cout << ans;
    return 0;
}
