#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){return a.second - a.first < b.second - b.first;}
    else{return a.second < b.second;}
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int s, e; cin >> s >> e;
        v[i] = {s,e};
    }
    sort(v.begin(), v.end(), compare);

    int res = 1;
    int end = v[0].second;

    for(int i=1;i<n;i++){
        if(v[i].first<end){continue;}
        end = v[i].second; res++;
    }

    cout << n -res;
    return 0;
}