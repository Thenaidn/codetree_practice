#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int a, b, n, m;
string t, t2;

vector<int> order;
vector<vector<int>> nextPos;

bool IsPossible(int mid) {
    vector<bool> deleted(t.size(), false);


    for (int i = 0; i < mid; i++) {
        deleted[order[i]] = true;
    }


    int pos = 0; 
    for (int i = 0; i < t.size(); i++) {
        if (deleted[i]) { continue; }

        if (t[i] == t2[pos]) {
            pos++;
            if (pos == t2.size()) { return true; }
        }
    }
    return false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t >> t2;

    int len = t.size();
    order.resize(len);

    for (int i = 0; i < len; i++) {
        cin >> order[i];
        order[i]--;
    }

    int left = 0; int right = len; int res = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (IsPossible(mid)) {
            res = mid + 1;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << res << endl;

    return 0;
}
