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
    int prev = c[0];
    if(prev==0){res++;}
    for(int i=1;i<n;i++){
        if(c[i] != prev && c[i] == 0){
            res++;
        }
        prev = c[i];
    }
    cout << res;
    // 여기에 코드를 작성해주세요.
    return 0;
}