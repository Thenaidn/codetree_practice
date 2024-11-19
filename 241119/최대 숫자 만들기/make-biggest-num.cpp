#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 다음 custom comparator를 이용하면
// 숫자들을 내림차순으로 정렬해줍니다.
// 정렬 이후의 결과가
// a가 더 앞, b가 더 뒤에 오는 것이 맞다면
// true / 아니라면 false가 되게끔 만들면 됩니다.
bool cmp(int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

int main() {
    int n = 5;
    int arr[500000] = { 0, };
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++)
        cout << arr[i] << "";
    return 0;
}


