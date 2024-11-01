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

int main() {
    unordered_map<int, int> umap; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        umap[arr[i]] = 0;
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) { continue; }
            int sum = arr[i] + arr[j];
            if (umap.find(sum) == umap.end()) {
                umap[sum] = 1;
            }
            else {
                int tmp = umap[sum];
                umap.erase(sum);
                umap[sum] = tmp + 1;
            }
        }
    }

    cout << umap[m] / 2;

    return 0;


}