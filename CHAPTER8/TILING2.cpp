#include <iostream>
#include <cstring>

using namespace std;

int N;
int cache[101];

int solve(int width) {
    if (width == 1) return 1;
    else if (width == 2) return 2;

    int& ret = cache[width];
    if (ret != -1) {
        cout << "width:" << width << " repeated case!!" << endl;
        return ret;
    }
    return ret = (solve(width - 2) + solve(width - 1)) % 1000000007;
}

int main(void) {
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << solve(N) << endl;

    return (0);
}