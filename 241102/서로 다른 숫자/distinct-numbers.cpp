#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

#define MAX_N 100001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;

int arr[4][MAX_N];

string t;

unordered_set<int> set1;
int main() {
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (set1.find(a) == set1.end()) {
            set1.insert(a);
            res++;
        }
    }




    cout << res;

    return 0;

}