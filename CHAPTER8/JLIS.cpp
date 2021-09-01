#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_SIZE 100

int N, M;
int A[MAX_SIZE], B[MAX_SIZE];
int cache[MAX_SIZE + 1][MAX_SIZE + 1];

const int INF = 987654321;

int solve(int idxA, int idxB) {
    int a = idxA == -1 ? -INF : A[idxA];
    int b = idxB == -1 ? -INF : B[idxB];
    int pivot = max(a, b);

    // 중복된 숫자가 없고, A와 B 모두 크기가 1 이상 
    int& ret = cache[idxA + 1][idxB + 1];
    if (ret != -2) return ret;

    ret = 2;
    for (int nextA = idxA + 1; nextA < N; ++nextA) {
        if (pivot < A[nextA])
            ret = max(solve(nextA, idxB) + 1, ret);
    }
    for (int nextB = idxB + 1; nextB < M; ++nextB) {
        if (pivot < B[nextB])
            ret = max(solve(idxB, nextB) + 1, ret);
    }
    return ret;
}

int main(void) {
    int C;
    cin >> C;
    for (int c = 0; c  < C; ++c) {
        for (int i = 0; i < MAX_SIZE; ++i) 
            for (int j = 0; j < MAX_SIZE; ++j)
                cache[i][j] = -2;
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        for (int i = 0; i < M; ++i)
            cin >> B[i];

        // for (int i = 0; i < N; ++i)
        //     cout << A[i] << " ";
        // cout << endl;
        // for (int i = 0; i < M; ++i)
        //     cout << B[i] << " ";
        // cout << endl;

        cout << solve(-1, -1) - 2 << endl;
    }
}