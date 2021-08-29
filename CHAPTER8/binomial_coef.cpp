#include <iostream>

using namespace std;

int bino(int n, int r) {
    if (r == 0 || n == r) return 1;
    cout << n << ", " << r << endl;
    return bino(n - 1, r - 1) + bino(n - 1, r);
}

// 이미 구한 값을 사용하기 위한 메모리 공간을 생성합니다.
int cache[30][30];
int binoMemoization(int n, int r) {
    if (r == 0 || n == r) return 1;

    int& ret = cache[n][r];
    if (ret != -1) return ret;

    cout << n << ", " << r << endl;
    // 처음으로 계산하는 시점에서 cache에 계산 값을 저장해두고, 저장된 값이 있다면 이를 사용합니다.
    ret = binoMemoization(n - 1, r - 1) + binoMemoization(n - 1, r);
    return ret;
}

int main(void) {
    int N, R;
    cin >> N >> R;
    cout << bino(N, R) << endl;

    memset(cache, -1, sizeof(cache));
    cout << binoMemoization(N, R) << endl;
}