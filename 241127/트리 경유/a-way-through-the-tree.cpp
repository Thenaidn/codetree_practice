#include <iostream>
#include <set>
using namespace std;

set<int> painted;
int find(int dest){
    while(dest > 1){
        dest /= 2;
        if(painted.find(dest) != painted.end()){ return dest ;}
    }
    return 0;
}

int main() {
   
    int n, q; cin >> n >> q;
    for(int i=0;i<q;i++){
        int a; cin >> a;
        int res = find(a);
        if(res == 0){painted.insert(a);}
        cout << res << endl;
    }
    return 0;
}