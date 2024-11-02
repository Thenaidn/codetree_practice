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
    unordered_map<string, int> umap; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string aa;
        cin >> aa;
        string t;
        unordered_map<char, int> tmap;
        for (int j = 0; j < aa.size(); j++) {
            char tmp = aa[j];
            if (tmap.find(tmp) == tmap.end()) {
                tmap[tmp] = 1;
            }
            else {
                int tt = tmap[tmp];
                tmap.erase(tmp);
                tmap[tmp] = tt + 1;
            }
        }
        vector<pair<char, int>> vec(tmap.begin(), tmap.end());

        sort(vec.begin(), vec.end(), cmp);
        for (int j = 0; j < vec.size(); j++) {
            t += vec[j].first;
            t += to_string(vec[j].second);
        }

        if (umap.find(t) == umap.end()) {
            umap[t] = 1;
        }
        else {
            int tt = umap[t];
            umap.erase(t);
            umap[t] = tt + 1;
        }
    }
    
    int count = 0;

    for (pair<string, int> p : umap) {
        count = max(count, p.second);
    }
    
    cout << count;

    return 0;


}