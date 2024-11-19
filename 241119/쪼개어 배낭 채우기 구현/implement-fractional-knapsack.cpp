#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<float, float> a, pair<float, float> b) {
    if (a.second / a.first == b.second / b.first) {
        return a.first > b.first;
    }
    else {
        return a.second / a.first > b.second / b.first;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    vector<pair<float, float>> jewels(n);

    for (int i = 0; i < n; i++) {
        float a, b; cin >> a >> b;
        jewels[i] = { a,b };
    }

    sort(jewels.begin(), jewels.end(), compare);
    float res = 0;

    for (int i = 0; i < n; i++) {
        if (m == 0) { break; }

        if (m >= jewels[i].first) {
            m -= jewels[i].first;
            res += jewels[i].second;
        }
        else {
            res += m * jewels[i].second / jewels[i].first ;
            m = 0;
        }
    }

    printf("%.3f", res);
    return 0;
}