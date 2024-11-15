#include <iostream>

using namespace std;
int n;
    int arr[100000] = {0,};
void search(int target){
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
    
    cout << idx+1 << endl; // 45가 있는 인덱스인 4가 답이 됩니다.
}

int main() {
    int target = 45;

    int a,b; cin >> n >> b;

    for(int i=0;i<n;i++){cin >> arr[i];}
    for(int i=0;i<b;i++){cin >> a; search(a);}
    
    
    return 0;
}
