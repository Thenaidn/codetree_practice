#include <iostream>
using namespace std;

int n;
int arr[100000] = {0,};
int search(int target){
    int idx = -2;

    // 이진탐색을 진행합니다.
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == target) { // 찾았다면 해당 index를 반환합니다.
            idx = mid;
            break;
        }
        
        if(arr[mid] > target) // 찾으려는 숫자가 더 작다면
            right = mid - 1;  // 왼쪽 구간으로 이동해야 합니다.
        else                  // 찾으려는 숫자가 더 크다면
            left = mid + 1;   // 오른쪽 구간으로 이동해야 합니다.
    }
    
    return idx+1;
}
int LowerBound(int target) {
    int left = 0;                          // 첫 번째 원소의 위치로 설정합니다.
    int right = n - 1;                     // 마지막 원소의 위치로 설정합니다.
    int min_idx = n;                       // 최소이므로, 답이 될 수 있는 값보다 더 큰 값으로 설정합니다.
    while (left <= right) {                // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2;      // 가운데 위치를 선택합니다.
        if(arr[mid] >= target) {           // 만약에 선택한 원소가 target보다 같거나 크다면 
            right = mid - 1;               // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            min_idx = min(min_idx, mid);   // 같거나 큰 값들의 위치 중 최솟값을 계속 갱신해줍니다.
        }
        else                               
            left = mid + 1;                // 작은 경우라면 left를 바꿔줍니다.
    }

    return min_idx;                        // 조건을 만족하는 최소 index 값을 반환합니다.
}
int UpperBound(int target) {
    int left = 0;                          // 첫 번째 원소의 위치로 설정합니다.
    int right = n - 1;                     // 마지막 원소의 위치로 설정합니다.
    int min_idx = n;                       // 최소이므로, 답이 될 수 있는 값보다 더 큰 값으로 설정합니다.
    while (left <= right) {                // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2;      // 가운데 위치를 선택합니다.
        if(arr[mid] > target) {            // 만약에 선택한 원소가 target보다 크다면 
            right = mid - 1;               // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            min_idx = min(min_idx, mid);   // 큰 값들의 위치 중 최솟값을 계속 갱신해줍니다.
        }
        else                               
            left = mid + 1;                // 같거나 작은 경우라면 left를 바꿔줍니다.
    }

    return min_idx;                        // 조건을 만족하는 최소 index 값을 반환합니다.
}
int CustomBound(int target) {
    int left = 0;                          // 첫 번째 원소의 위치로 설정합니다.
    int right = n - 1;                     // 마지막 원소의 위치로 설정합니다.
    int max_idx = -1;                      // 최대이므로, 답이 될 수 있는 값보다 더 작은 값으로 설정합니다.
    while (left <= right) {                // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2;      // 가운데 위치를 선택합니다.
        if(arr[mid] <= target) {           // 만약에 선택한 원소가 target보다 같거나 작다면 
            left = mid + 1;                // 오른쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 left를 바꿔줍니다.
            max_idx = max(max_idx, mid);   // 같거나 작은 값들의 위치 중 최댓값을 계속 갱신해줍니다.
        }
        else                               
            right = mid - 1;               // 값이 더 큰 경우라면 right를 바꿔줍니다.
    }

    return max_idx;                        // 조건을 만족하는 최대 index 값을 반환합니다.
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n; int a; cin >> a;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<a;i++){
        int b; cin >> b;
        if(search(b)==-1){cout << -1 << endl;}
        else{cout << LowerBound(b) + 1 << endl;}
    }
    return 0;
}