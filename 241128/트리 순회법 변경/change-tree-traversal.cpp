#include <iostream>
#include <map>
using namespace std;

map<int, pair<int, int>> tree;

int main() {
    // 여기에 코드를 작성해주세요.
    int[10001] preorder;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> preorder[i];
    }
    tree[preorder[0]] = {-1, -1};
    int prev = preorder[0];
    
    int i=1;
    while(prev > preorder[i]){
        tree[prev] = { preorder[i] , -1};
        prev = preorder[i];
    }
    i--;
    prev = preorder[i];


    for (; i<n;i++){

    }


    return 0;
}