#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    pair<int, int> segments[7] = {
        make_pair(1, 5),
        make_pair(4, 7),
        make_pair(3, 6),
        make_pair(5, 10),
        make_pair(9, 13),
        make_pair(8, 15),
        make_pair(12, 16),
    };
    int n = 7;
    //int k = 11;

    // 주어진 좌표의 범위가 큰 경우에는
    // 각 선분을 두 지점으로 나눠서
    // +1, -1로 담은 뒤,
    // 정렬해줍니다.
    vector<pair<int, int> > points;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2; cin >> x1 >> x2;
        //tie(x1, x2) = segments[i];
        points.push_back(make_pair(x1, +1)); // 시작점
        points.push_back(make_pair(x2, -1)); // 끝점
    }

    // 정렬을 진행합니다.
    sort(points.begin(), points.end());

    // x = k 전까지
    // 각 위치에 적혀있는 숫자들의 합을 구해줍니다.

    int res = 0;
    int sum_val = 0;
    int tmp = 0;
    for (int j = 0; j <= 2 * n - 1; j++) {
        int k = points[j].first;
        for (int i = 0; i < 2 * n; i++) {
            int x, v;
            tie(x, v) = points[i];

            // x가 k 이상이 되면 종료합니다.
            if (x >= k)
                break;

            // 적혀있는 가중치를 전부 더해줍니다.
            sum_val += v;
        }
        res = max(sum_val, res);
        sum_val = 0;
    }
    tmp = 0;
    for (int j = 0; j <= 2 * n - 1; j++) {
        int k = points[j].second;
        for (int i = 0; i < 2 * n; i++) {
            int x, v;
            tie(x, v) = points[i];

            // x가 k 이상이 되면 종료합니다.
            if (x >= k)
                break;

            // 적혀있는 가중치를 전부 더해줍니다.
            sum_val += v;
        }
        res = max(sum_val, res);
        sum_val = 0;
    }
    for (int j = 0; j <= 2 * n - 1; j++) {
        int k = points[j].second - 1;
        for (int i = 0; i < 2 * n; i++) {
            int x, v;
            tie(x, v) = points[i];

            // x가 k 이상이 되면 종료합니다.
            if (x >= k)
                break;

            // 적혀있는 가중치를 전부 더해줍니다.
            sum_val += v;
        }
        res = max(sum_val, res);
        sum_val = 0;
    }
    // x = k에 겹쳐져 있는 선분의 수 = 2
    cout << res << endl;
    return 0;
}