#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 101

const int MOD = 10 * 1000 * 1000;

int N;
int cache[MAX_SIZE][MAX_SIZE];

int poly(int n, int first) {
    if (n == first) return 1;

    int& ret = cache[n][first];
    if (ret != -1) return ret;

    ret = 0;
    for (int second = 1; second <= n - first; ++second) {
        int add = second + first - 1;
        add *= poly(n - first, second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int main(void) {
    int C;
    cin >> C;
    for (int c = 0; c < C; ++c) {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            ans = (ans + poly(N, i)) % MOD;
        }
        cout << ans << endl;
    }
}