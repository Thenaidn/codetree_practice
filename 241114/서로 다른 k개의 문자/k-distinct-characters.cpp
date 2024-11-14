#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;

int main() {
    string t; int k;
    int left = 0; int right = 1;
    unordered_map<char, int> in;
    cin >> t >> k;
    in.insert({ t[0], 1 });
    int res = 1;
    for (int i = 1; i < t.size(); i++) {
        if (in.size() <= k) {
            if (in.find(t[i]) == in.end()) {
                in.insert({ t[i], 1 });
            }
            else { in[t[i]] += 1; }
        }
        if(in.size() > k){
            while (in.size() > k) {
                in[t[left]] -= 1;
                if (in[t[left]] == 0) {
                    in.erase(t[left]);
                }
                left++;
            }
        }
        
        res = max(res, i - left + 1);
    }
    cout << res;
    return 0;
}