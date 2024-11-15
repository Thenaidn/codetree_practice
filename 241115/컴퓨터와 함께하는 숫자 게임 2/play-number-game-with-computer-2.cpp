#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int game_duration(long long m, long long a, long long b) {
    int min_turns = INT_MAX;
    int max_turns = 0;


    for (long long num = a; num <= b; num++) {
        int turns = 0;
        long long left = 1, right = m;


        while (left <= right) {
            long long mid = (left + right) / 2;
            turns++;
            if (mid == num) break; 
            else if (mid < num) left = mid + 1;  
            else right = mid - 1;  
        }


        min_turns = min(min_turns, turns);
        max_turns = max(max_turns, turns);
    }

    cout << min_turns << " " << max_turns << endl;
    return 0;
}

int main() {
    long long m, a, b;
    cin >> m >> a >> b;
    game_duration(m, a, b);
    return 0;
}
