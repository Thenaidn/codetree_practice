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


int main() {
    cin >> n;
    int arr1[MAX_N]; int arr2[MAX_N];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    unordered_set<int> set1;
    unordered_set<int> set2;

    for (int i = 0; i < n; i++)
        set1.insert(arr1[i]);

    for (int i = 0; i < m; i++)
        set2.insert(arr2[i]);


    for (int i = 0; i < m; i++) {
        if (set1.find(arr2[i]) == set1.end())
            cout << 0;
        else
            cout << 1;
        cout << endl;
    }


    return 0;

}