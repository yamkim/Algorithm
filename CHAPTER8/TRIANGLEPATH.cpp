#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100
int N, path[MAX_SIZE][MAX_SIZE];
int cache[MAX_SIZE][MAX_SIZE];

int solve(int y, int x) {
    if (y == N - 1) return path[y][x];

    int& ret = cache[y][x];
    if (ret != -1) {
        cout << "repeated case: (" << y << ", " << x << ")" << endl;
        return ret;
    }

    cout << "visited case: (" << y << ", " << x << ")" << endl;
    // 남은 부분 문제(두 solve 결과를 비교하는 부분)가 전체 결과 값에 영향을 줍니다. 
    // -> 최적 부분 구조(optimal substructure)
    // ret = max(solve(y + 1, x), solve(y + 1, x + 1)) + path[y][x];
    ret = max(solve(y + 1, x + 1), solve(y + 1, x)) + path[y][x];
    return ret;
}

int main(void) {
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j)
            cin >> path[i][j];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << path[i][j] << " ";
        cout << endl;
    }
    cout << solve(0, 0) << endl;
}