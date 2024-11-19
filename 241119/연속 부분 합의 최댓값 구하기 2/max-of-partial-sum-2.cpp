#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    int nums[100000];
    int res = 0;
    int ans = 0;
    for(int i=0;i<n;i++){cin>>nums[i];}
    for(int i=0;i<n;i++){
        res+=nums[i];
        if(res < 0){res = 0;}
        ans = max(res,ans);
    }
    if(ans == 0){
       sort(nums, nums+n);
       ans = nums[n - 1]; 
    }
    cout << ans;
    return 0;
}