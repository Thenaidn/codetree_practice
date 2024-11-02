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
    unordered_map<int, int> umap[2]; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap

    cin >> n;
    m = 0;
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < n; i++) {
            cin >> arr[k][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            umap[0][arr[0][i] + arr[1][j]]++;

            umap[1][arr[2][i] + arr[3][j]]++;
        }
    }

    int count = 0;
    for (pair<int,int> p : umap[0]) {
        if (umap[1].find(-1 * p.first) != umap[1].end()) {
            count += p.second * umap[1][-1 * p.first];
        }
    }
    cout << count;

    return 0;


}