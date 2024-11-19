#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int res=0;
    res+=n/5;
    n%=5;
    res+=n/2;
    n%=2;
    if(n == 1){
        res+=2;
    }
    cout<<res;
    return 0;
}