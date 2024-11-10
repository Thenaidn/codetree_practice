#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unordered_set>

using namespace std;

int main() {
    pair<int, int> segments[6] = {
        make_pair(1, 5),
        make_pair(4, 7),
        make_pair(3, 6),
        make_pair(9, 13),
        make_pair(8, 15),
        make_pair(12, 16),
    };
    int n = 6;

    // 각 선분을 두 지점으로 나눠 담은 뒤,
    // 정렬해줍니다.
    // 이때 (x좌표, +1-1값, 선분 번호)
    // 형태로 넣어줍니다.
    // +1은 시작점
    // -1은 끝점을 뜻합니다.
    vector<tuple<int, int, int> > points;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2; cin >> x1 >> x2;
        //tie(x1, x2) = segments[i];
        points.push_back(make_tuple(x1, +1, i)); // 시작점
        points.push_back(make_tuple(x2, -1, i)); // 끝점
    }

    // 정렬을 진행합니다.
    sort(points.begin(), points.end());

    // 각 점을 순서대로 순회합니다.
    // 등장하고 아직 사라지지 않은
    // 선분을 hashset으로 관리합니다.
    unordered_set<int> segs;

    int ans = 0; // 서로 다른 구간의 수를 저장합니다.
    for (int i = 0; i < 2 * n; i++) {
        int x, v, index;
        tie(x, v, index) = points[i];

        // 시작점인 경우입니다.
        if (v == +1) {
            // 남아있는 선분이 없다면
            // 답을 갱신합니다.
            if ((int)segs.size() == 0)
                ans++;

            // 해당 선분 번호를 hashset에 넣어줍니다.
            segs.insert(index);
        }

        // 끝점인 경우입니다.
        else {
            // 해당 선분을 제거합니다.
            segs.erase(index);
        }
    }

    // 서로 다른 구간의 수 = 2
    cout << ans << endl;
    return 0;
}