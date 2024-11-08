#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    pair<int, int> edges[2500];
    set<pair<int, int>> nums;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = { a,b };
        nums.insert(edges[i]);
    }
    map<int, int> mapper;
    map<int, int> mappery;
    int cnt = 1;
    for (pair<int, int> i : nums) {
        int x, y;

        mapper[i.first] = cnt;
        mappery[cnt] = i.second;
        cnt++;
    }

    for (int j = 0; j < q; j++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int res = 0;

        int x1, x2;

        auto x11 = mapper.lower_bound(a);


        auto x22 = mapper.lower_bound(c + 1);
        
        if (x22 == mapper.end()) {
            x22--;
            if (x22->first > c) {
                x22 == mapper.end();
            }
        }
        else {
            x22--;
        }

        /*for (int i = 1; i <= mapper.size(); i++) {
            if (mapper[i] >= a) {
                x1 = i;
                break;
            }
        }*/
        /*for (int i = mapper.size(); i >= x1; i--) {
            if (mapper[i] <= c) {
                x2 = i;
                break;
            }
        }*/

        if (x11 != mapper.end() && x22 != mapper.end()) {
            x1 = x11->second; x2 = x22->second;
            
            res = x2 - x1 + 1;

            for (int i = x1; i <= x2; i++) {
                if (mappery[i] < b || mappery[i] > d) {
                    res--;
                }
            }
        }

        cout << res << endl;
    }


    // treeset에서 정점을 작은 번호부터 뽑으면서
    // 각 정점별로 1번부터 순서대로 매칭하여
    // 그 결과를 hashmap에 넣어줍니다.




    return 0;
}