#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int edges[100001];
    set<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> edges[i];
        nums.insert(edges[i]);
    }
    map<int, int> mapper;
    int cnt = 1;
    for (int i : nums) {
        mapper[i] = cnt;
        cnt++;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int x1, x2;
        auto x11 = mapper.lower_bound(a);


        auto x22 = mapper.lower_bound(b + 1);

        if (x22 == mapper.end()) {
            x22--;
            if (x22->first > b) {
                x22 == mapper.end();
            }
        }
        else {
            x22--;
        }

        if (x11 != mapper.end() && x22 != mapper.end()) {
            x1 = x11->second; x2 = x22->second;

            cout << x2 - x1 + 1 << endl;
        }

        
    }


    // treeset에서 정점을 작은 번호부터 뽑으면서
    // 각 정점별로 1번부터 순서대로 매칭하여
    // 그 결과를 hashmap에 넣어줍니다.




    return 0;
}