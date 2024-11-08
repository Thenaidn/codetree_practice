#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int arr[100001];
    vector<int> v;
    int n,q;
    cin >> n>> q;
    int p=0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());

    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        int count1 = 0; int count2 = 0;
        for(int j:v){
            if(j < a){
                count1++;
            }
        }
        count2 = count1;
        for(int j=count1;j<v.size();j++){
            if(v[j] <= b){count2++;}
            else{break;}
        }
        cout << count2 - count1 << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}