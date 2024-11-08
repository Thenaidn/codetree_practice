#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    short arr[1000001] = { 0 };
    vector<int> v;
    int n, q;
    cin >> n >> q;
    int p = 0;
    int afds;

    for (int i = 0; i < n; i++) {
        cin >> afds;
        
        v.push_back(afds);
    }
    sort(v.begin(), v.end());
    map<int,int> map;

    int c = 1;
    for(int i:v){
        map[i]=c++;
    }

    for (int j = 0; j < q; j++) {
        int a, b, i;
        cin >> a >> b;
        int count1 = 0; 
        for(i = a - 1; i>=0;i--){
            if(map.find(i)!=map.end()){
                count1 = map[i];
                break;
            }
        }
        int count2 = count1;
        for(i = b; i>=a - 1;i--){
            if(map.find(i)!=map.end()){
                count2 = map[i];
                break;
            }
        }
        cout << count2 - count1 << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}