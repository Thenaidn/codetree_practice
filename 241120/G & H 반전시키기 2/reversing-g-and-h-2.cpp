#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string t1, t2; int n;
    cin >> n >> t1 >> t2;
    vector<int> c(n);

    int res = 0;
    for(int i=0;i<n;i++){
        if(t1[i] != t2[i]){c[i] = 0;}
        else{c[i] = 1;}
    }
    int currentzero = 0;
    for(int i=n - 1;i>=0;i--){
        if(c[i] == currentzero){
            res++;
            currentzero = (currentzero == 0) ? 1 : 0;
        }
    }
    cout << res;
    // 여기에 코드를 작성해주세요.
    return 0;
}