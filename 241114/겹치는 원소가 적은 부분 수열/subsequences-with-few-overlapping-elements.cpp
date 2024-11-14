#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;

int main() {
    int t[100000]; int k; int n;
    int left = 0; int right = 1;
    unordered_map<int, int> in;
    cin >> n >> k;
    for (int i = 0; i < n; i++) { cin >> t[i]; }
    in.insert({ t[0], 1 });
    int res = 1;
    for (int i = 1; i < n; i++) {
        if (in.find(t[i]) == in.end()) {
            in.insert({ t[i], 1 });
        }
        else { in[t[i]] += 1; }

        if(in[t[i]] > k) {
            while (in[t[i]] > k) {
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