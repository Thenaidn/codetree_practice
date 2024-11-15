#include <iostream>
#include <unordered_set>
using namespace std;

long long n;
int arr[100000] = {0,};
int search(long long target){

    int count = 0;
    // 이진탐색을 진행합니다.
    long long left = 1, right = n;
    while (left <= right) {
        count++;
        long long mid = (left + right) / 2;
        if(mid == target) { // 찾았다면 해당 index를 반환합니다.
            return count;
            break;
        }
        
        if(mid > target) // 찾으려는 숫자가 더 작다면
            right = mid - 1;  // 왼쪽 구간으로 이동해야 합니다.
        else                  // 찾으려는 숫자가 더 크다면
            left = mid + 1;   // 오른쪽 구간으로 이동해야 합니다.
    }
}


int main() {
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // 여기에 코드를 작성해주세요.
    cin >> n; long long a, b; cin >> a >> b;
    int mi = n; int ma = 0;
    for(int i=a;i<=b;i++){
        long long res = search(i);
        mi = min(mi,res);
        ma = max(ma,res);
    }
    cout << mi << " " << ma;
    return 0;
}