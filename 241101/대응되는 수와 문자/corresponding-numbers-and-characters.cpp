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

string arr[MAX_N];

string t;

int main() {
    unordered_map<string, int> umap; // 정수를 관리할 hashmap을 선언합니다. => 빈 hashmap

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        umap[arr[i]] = i + 1;
    }

    int res = 0;

    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        try {
            int num = stoi(tmp);
            cout << arr[num - 1] << endl;
        }
        catch (const std::invalid_argument& e) {
            cout << umap[tmp] << endl;
        }
    }

    //cout << res;

    return 0;


}