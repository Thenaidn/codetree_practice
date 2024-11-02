#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
using namespace std;

#define MAX_N 5001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;

int arr[4][MAX_N];

string t;

bool cmp(pair<char, int> a, pair<char, int>b) {
    return a.first > b.first;
}

int main() {
    unordered_map<char, int> umap; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap

    cin >> t;

    for (int i = 0; i < t.size(); i++) {
        char c = t[i];
        if (umap.find(c) == umap.end()) {
            umap[c] = 1;
        }
        else {
            int tmp = umap[c];
            umap.erase(i);
            umap[c] = ++tmp;
        }
    }
   
    
    int count = 0;

    for (pair<char, int> p : umap) {
        if (p.second == 1) {
            cout << p.first;
            return 0;
        }
    }
    
    //cout << count;

    return 0;


}