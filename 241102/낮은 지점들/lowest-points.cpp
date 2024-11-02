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


int main() {
    unordered_map<int, int> umap; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (umap.find(a) == umap.end()) {
            umap[a] = b;
        }
        else {
            umap[a] = min(umap[a], b);
        }
    }

    int res = 0;
    for (pair<int, int> p : umap) {
        res += p.second;
    }
    cout << res;
    return 0;


}