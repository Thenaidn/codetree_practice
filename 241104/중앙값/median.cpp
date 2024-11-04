#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;

#define MAX_N 100001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;


string t;

vector<int> v;
int main() {
    float res = 0;
    cin >> n;
    

    for (int i = 0; i < n; i++) {
        priority_queue<int, vector<int>, greater<int>> top;
        priority_queue<int> bot;
        cin >> m;
        for (int j = 1; j <= m; j++) {
            
            cin >> a;
            if (j % 2 == 1) {
                bot.push(a);
            }
            else {
                top.push(a);
            }
            if (j >= 2) {
                if (bot.top() > top.top()) {
                    int tmp = top.top(); int tmp2 = bot.top();
                    bot.pop(); top.pop();
                    bot.push(tmp); top.push(tmp2);
                }
            }
            if (j % 2 == 1) { cout << bot.top() << " "; }
            
        }cout << endl;

    }


    //printf("%.2f", res);

    return 0;
}