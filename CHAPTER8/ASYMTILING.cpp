#include <iostream>
#include <cstring>

using namespace std;

int N;
int cache[101];
const int MOD = 1000000007;

// 1이하로 설정한 이유: asymmetric에서 0이 들어올 때 뺴주어야하기 때문
int tiling(int width) {
    if (width <= 1) return 1;
    else if (width == 2) return 2;

    int& ret = cache[width];
    if (ret != -1) {
        // cout << "width:" << width << " repeated case!!" << endl;
        return ret;
    }
    return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int asymmetric(int width) {
    int ret = tiling(width);
    if (width % 2 == 1) {
        ret = (ret - tiling(width / 2) + MOD) % MOD;
    } else {
        ret = (ret - tiling(width / 2) + MOD) % MOD;
        ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
    }
    return ret;
}

int main(void) {
    int C;
    cin >> C;
    for (int c = 0; c < C; ++c) {
        cin >> N;
        memset(cache, -1, sizeof(cache));
        cout << asymmetric(N) << endl;
    }
    return (0);
}