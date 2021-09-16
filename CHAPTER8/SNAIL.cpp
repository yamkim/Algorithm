#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX_DAYS 100
#define MAX_DEPTH 1000

int N, M;
double cache[MAX_DAYS][MAX_DEPTH];

double climb(int days, int climbed) {
    if (days == M) return climbed >= N ? 1 : 0;

    double& ret = cache[days][climbed];
    if (ret != -1) {
        // cout << "repeated case!" << endl;
        return ret;
    }
    ret = 0.75 * climb(days + 1, climbed + 2);
    ret += 0.25 * climb(days + 1, climbed + 1);
    return ret;
}

int main(void) {
    int C;
    cin >> C;
    for (int c = 0; c < C; ++c) {
        for (int i = 0; i < MAX_DAYS; ++i)
            for (int j = 0; j < MAX_DEPTH; ++j)
                cache[i][j] = - 1.0;
        cin >> N >> M;
        cout << fixed;
        cout.precision(10);
        cout << climb(0, 0) << '\n';
    }
    return (0);
}