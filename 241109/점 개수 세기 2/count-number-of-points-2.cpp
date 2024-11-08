#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    set<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        points.insert({ a, b });
    }

    map<int, vector<int>> y_values_map;
    for (const auto& p : points) {
        y_values_map[p.first].push_back(p.second);
    }

    for (auto& entry : y_values_map) {
        sort(entry.second.begin(), entry.second.end());
    }

    for (int j = 0; j < q; j++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int result = 0;

        auto start = y_values_map.lower_bound(a);
        auto end = y_values_map.upper_bound(c);

        for (auto it = start; it != end; ++it) {
            auto lower = lower_bound(it->second.begin(), it->second.end(), b);
            auto upper = upper_bound(it->second.begin(), it->second.end(), d);
            result += distance(lower, upper);
        }

        cout << result << endl;
    }

    return 0;
}