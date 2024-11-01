#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

#define MAX_N 10001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;

string arr[MAX_N];

string t;

int main() {
    unordered_map<string, int> umap; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        if (umap.find(t) != umap.end()) {
            int tmp = umap[t];
            umap.erase(t);
            umap[t] = tmp + 1;
        }
        else { umap[t] = 1; }
    }

    int res = 0;

    for (pair<string, int> p : umap) {
        res = max(p.second, res);
    }

    cout << res;

    return 0;


}