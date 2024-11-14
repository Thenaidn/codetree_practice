#include <iostream>
#include<string>
#include <unordered_set>
using namespace std;

int main() {
    string t;
    int left = 0; int right = 1;
    unordered_set<char> in;
    cin >> t;
    in.insert(t[0]);
    int res = 1;
    for (int i = 1; i < t.size(); i++) {
        if (in.find(t[i]) == in.end()) {
            in.insert(t[i]);
        }
        else {
            while (in.find(t[i]) != in.end()) {
                in.erase(t[left]);
                left++;
            }
            in.insert(t[i]);
        }
        int s = in.size();
        res = max(res, s);
    }
    cout << res;
    return 0;
}