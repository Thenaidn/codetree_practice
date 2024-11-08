#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 11;

int arr[MAX_N] = { 0 };
int dp[MAX_N] = {0};

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++) { 
        cin >> arr[i]; 
        if(i>0){arr[i]+=arr[i-1];}
    }

    int m=0;

    for(int i=0;i<a;i++){
        int sum = 0;
        if(arr[i] == b){m++;}
        if(i>0){
            for(int j=0;j<i;j++){
                sum = arr[i] - arr[j];
                if(sum == b){m++;}
            }
            
        }
    }

    cout << m;
    return 0;
}