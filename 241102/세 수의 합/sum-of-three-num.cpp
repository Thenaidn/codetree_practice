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
        umap[arr[i]]++;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        int target2 = m - arr[i];
        for (int j = 0; j < n; j++) {
            if (i == j) { continue; }
            int target = target2 - arr[j];

            if (umap[target] > 0) {
                count += umap[target];

                if (target == arr[j]) {
                    count--;
                }
                if (target2 == arr[i]) {
                    count--;
                }
            }
        }
        
    }

    cout << count / 6;

    return 0;


}