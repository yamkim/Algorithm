#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100

int N, S[MAX_SIZE];
int cache[MAX_SIZE + 1];

// S[0]을 시작점으로 고정하는 경우
// int solve(int start) {
//     int& ret = cache[start];
//     if (ret != -1) {
//         cout << "repeated case: " << start << endl;
//         return ret;
//     }
//     ret = 1;
//     for (int next = start + 1; next < N; ++next) {
//         if (S[start] < S[next])
//             ret = max(solve(next) + 1, ret);
//     }
//     return (ret);
// }

int solve(int start) {
    int& ret = cache[start + 1];
    if (ret != -1) {
        cout << "repeated case: " << start << endl;
        return ret;
    }
    ret = 1;
    for (int next = start + 1; next < N; ++next) {
        if (start == -1 || S[start] < S[next])
            ret = max(solve(next) + 1, ret);
    }
    return (ret);
}


int main(void) {
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    // -1일 때, 없는 요소임에도 ret을 기본적으로 1로 설정했기 때문입니다.
    // cout << solve(0) << endl;
    cout << solve(-1) - 1 << endl; 

}