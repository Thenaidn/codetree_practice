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
    //vector<pair<int, int> > points;
    cin >> n;
    int points[200001] = { 0 };
    for (int i = 0; i < n; i++) {
        int x1, x2; cin >> x1 >> x2;
        //tie(x1, x2) = segments[i];
        points[x1]++; points[x2]--;
    }


    int res = 0;
    int sum_val = 0;
    for (int k = 1; k <= 200000; k++) {
        sum_val += points[k];


        res = max(sum_val, res);
    }
    

    // x = k에 겹쳐져 있는 선분의 수 = 2
    cout << res << endl;
    return 0;
}