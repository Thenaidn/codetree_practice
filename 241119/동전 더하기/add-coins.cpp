#include <iostream>
using namespace std;

int main() {
    int n, k;
    int coins[10];
    cin >> n >> k;
    for(int i=0;i<n;i++){cin>>coins[i];}
    int res = 0;
    for(int i=n-1;i>=0;i--){
        res += k / coins[i];
        k %= coins[i];
    }
    
    cout << res;
    return 0;
}