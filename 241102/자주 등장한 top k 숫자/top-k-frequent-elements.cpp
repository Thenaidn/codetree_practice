#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
using namespace std;

#define MAX_N 100001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;

int arr[MAX_N];

string t;

bool cmp(pair<int,int> a, pair<int,int>b){
    if (a.second == b.second) {
        return a.first > b.first;
    }
    else {
        return a.second > b.second;
    }
}

int main() {
    unordered_map<int, int> umap; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        umap[arr[i]]++;
    }

    int count = 0;

    vector<pair<int, int>> vec(umap.begin(), umap.end());
    
    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < m; i++) {
        cout << vec[i].first << " ";
    }

    return 0;


}