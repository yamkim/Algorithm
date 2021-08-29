#include <iostream>

using namespace std;

int N, board[100][100];
int cache[100][100];

bool isRange(int y, int x) {
    if (y >= 0 && y < N && x >= 0 && x < N)
        return true;
    return false;
}

bool jump(int y, int x) {
    if (!isRange(y, x)) return false;
    if (y == N - 1 && x == N - 1) return true;

    cout << "case: (" << y << ", " << x << ")" << endl;
    int& ret = cache[y][x];
    if (ret != -1) {
        cout << "repeated case: (" << y << ", " << x << ")" << endl;
        return ret;
    }

    int step = board[y][x];
    return ret = jump(y + step, x) || jump(y, x + step);
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    memset(cache, -1, sizeof(cache));
    if (jump(0, 0)) cout << "YES" << endl;
    else            cout << "NO" << endl;
}