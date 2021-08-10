#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
const int NUM_SWITCHES = 10;
const int NUM_CLOCKS = 16;

// 문자열은 마지막에 널 문자까지 포함되어야 하므로, 1 더합니다.
const char linked[NUM_SWITCHES][NUM_CLOCKS + 1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

// base case로서, 모든 시계가 12시를 가리키고 있는지 확인합니다.
bool areAligned(const vector<int>& clocks) {
    for (int i = 0; i < NUM_CLOCKS; ++i)
        if (clocks[i] != 12)
            return (false);
    return (true);
}

// 누적되는 경우가 아니므로, 누른 후 누른 결과를 되돌릴 필요는 없습니다.
// 해당 스위치에 대해 연결된 시계인지 확인 후, 맞다면 한 번 눌러서 시간을 3 더해주면 됩니다.
void pushSwitch(vector<int>& clocks, int switchNum) {
    for (int clock = 0; clock < NUM_CLOCKS; ++clock) {
        if (linked[switchNum][clock] == 'x') {
            int tmpTime = clocks[clock] + 3;
            clocks[clock] = tmpTime % 12 == 0 ? 12 : tmpTime;
        }
    }

}

int solve(vector<int>& clocks, int switchNum) {
    // 일단 switchNum이 16번 까지 눌러서 모든 스위치에 대해 동작시켰는지 확인하고,
    // 만약 각 시계가 12시를 가리키면 0을 반환하여 최솟값 연산에 영향을 주고,
    // 하나의 시계라도 12시를 가리키지 않으면 최솟값 연산을 수행하지 않기위해 INF를 반환합니다.
    if (switchNum == NUM_SWITCHES) 
        return areAligned(clocks) ? 0 : INF;   
    
    int ret = INF;
    // 버튼을 누르지 않는 경우도 있기 때문에, 먼저 cand 계산 후에
    // 버튼을 누르는 방식으로 구현합니다.
    for (int cnt = 0; cnt < 4; ++cnt) {
        int cand = solve(clocks, switchNum + 1) + cnt;
        ret = min(ret, cand);
        pushSwitch(clocks, switchNum);
    }
    return ret;
}

int main(void) {
    int C;
    cin >> C;
    for (int c = 0; c < C; ++c) {
        vector<int> clocks(NUM_CLOCKS);
        for (int i = 0; i < NUM_CLOCKS; ++i) {
            cin >> clocks[i];
        }
        cout << solve(clocks, 0) << endl;
    }

    return (0);
}