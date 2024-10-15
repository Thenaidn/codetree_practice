#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
using namespace std;

int a, b, t, k;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
vector<tuple<int, int, int, int, int>> balls; // (y, x, 방향, 무게, 번호)
int maps[51][51];

bool isinside(int y, int x) {
    return x >= 0 && x < a && y >= 0 && y < a;
}
bool compareb(int a, int b) {
    int speedA = get<3>(balls[a]);
    int speedB = get<3>(balls[b]);
    int numA = get<4>(balls[a]);
    int numB = get<4>(balls[b]);
    if (speedA == speedB) {
        return numA > numB;
    }
    return speedA > speedB;
}

void removeBalls() {
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < balls.size(); i++) {
        int y = get<0>(balls[i]);
        int x = get<1>(balls[i]);
        pos[y * a + x].push_back(i);
    }

    vector<tuple<int, int, int, int, int>> new_balls;
    for (auto& entry : pos) {
        if (entry.second.size() > k) {

            vector<int> indices = entry.second;
            int maxnum = 0;
            int weightsum = 0;

            for (int i = 0; i < entry.second.size(); i++) {
                maxnum = max(maxnum, get<4>(balls[entry.second[i]]));
                weightsum += get<3>(balls[entry.second[i]]);
            }
            tuple<int, int, int, int, int > newball =
                make_tuple(get<0>(balls[indices[0]]), get<1>(balls[indices[0]]), 
                    get<2>(balls[indices[0]]), weightsum, maxnum);

            new_balls.push_back(newball);
        }
        else {
            for (int i = 0; i < entry.second.size(); i++) {
                new_balls.push_back(balls[entry.second[i]]);
            }
        }
    }

    balls = new_balls;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> t;
    k = 1;
    balls.clear();

    for (int i = 0; i < b; ++i) {
        int x, y, v;
        char d;
        cin >> y >> x >> d >> v;
        x--; y--;
        int dir = (d == 'L') ? 0 : (d == 'U') ? 1 : (d == 'R') ? 2 : 3;
        balls.push_back(make_tuple(y, x, dir, v, i + 1));
        maps[y][x]++;
    }

    for (int time = 0; time < t; time++) {

        for (int i = 0; i < balls.size(); i++) {
            int y, x, dir, weight, num;

            tie(y, x, dir, weight, num) = balls[i];
            for (int step = 0; step < 1; step++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (!isinside(ny, nx)) {
                    dir = (dir + 2) % 4;
                    nx = x + dx[dir];
                    ny = y + dy[dir];
                    continue;
                }
                maps[y][x]--;
                x = nx;
                y = ny;
                maps[y][x]++;
            }
            balls[i] = make_tuple(y, x, dir, weight, num);
        }

        removeBalls();
    }

    int maxweight = 0;
    for (int i = 0; i < balls.size(); i++) {
        maxweight = max(maxweight, get<3>(balls[i]));
    }

    cout << balls.size() << " " << maxweight << "\n";
    return 0;
}