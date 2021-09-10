#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 100

int N;
int board[MAX_SIZE][MAX_SIZE];
int cache[MAX_SIZE + 1][MAX_SIZE + 1];
int cntCache[MAX_SIZE + 1][MAX_SIZE + 1];

int path(int y, int x) {
    if (y == N - 1) return board[y][x];

    int& ret = cache[y][x];
    if (ret != -1) {
        // cout << "[path] repeated case!" << endl;
        return ret;
    }

    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + board[y][x];
}

int count(int y, int x) {
    if (y == N - 1) return 1;

    int& ret = cntCache[y][x];
    if (ret != -1) {
        // cout << "[cnt] repeated case!" << endl;
        return ret;
    }

    ret = 0;
    if (path(y + 1, x) > path(y + 1, x))
        ret += count(y + 1, x);
    if (path(y + 1, x) < path(y + 1, x + 1))
        ret += count(y + 1, x + 1);
    if (path(y + 1, x) == path(y + 1, x + 1))
        ret += count(y + 1, x) + count(y + 1, x + 1);
    return max(path(y + 1, x), path(y + 1, x + 1)) + board[y][x];
}

int main(void) {
    int C;
    cin >> C;
    for (int c = 0; c < C; ++c) {
        memset(cache, -1, sizeof(cache));
        memset(cntCache, -1, sizeof(cntCache));
        cin >> N;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j <= i; ++j)
                cin >> board[i][j];
        cout << count(0, 0) << endl;
    }
}