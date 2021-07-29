#include <iostream>
#include <vector>

using namespace std;

// [0, 0] 기준으로 dx, dy를 더하면 8방에 대해 처리할 수 있습니다.
// [-1, 1] [ 0, 1] [ 1, 1]
// [-1, 0] [ 0, 0] [ 1, 0]
// [-1,-1] [ 0,-1] [ 1,-1]
const int DIR_SIZE = 8;
const int dx[DIR_SIZE] = {-1, -1, -1,  1, 1, 1,  0, 0};
const int dy[DIR_SIZE] = {-1,  0,  1, -1, 0, 1, -1, 1};

const int boardX = 5;
const int boardY = 5;
vector<string> board;

bool inRange(int y, int x) {
    if (y >= boardY || x >= boardX) {
        return (false);
    }
    return (true);
}

bool hasWord(int y, int x, const string& word) {
    if (!inRange(y, x)) return false;
    // WORD => ORD => RD => D 순서로 진행하므로, 첫 번째 글자만 봅니다.
    if (board[y][x] != word[0]) return false;
    // board[y][x] == word[0]이고, length가 1인 경우는 모든 단어가 일치하는 경우입니다.
    if (word.length() == 1) return true;

    for (int i = 0; i < DIR_SIZE; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (hasWord(ny, nx, word.substr(1))) {
            return (true);
        }
    }
    // 위의 for 문에서 모든 방향을 전부 봤는데,
    // hasWord가 일치하는 경우를 찾지 못하면 false로 간주합니다.
    return (false);
}

bool checkWord(const string& target) {
    // board에서 target을 비교하기 위한 시작 위치를 정하기 위한 루프입니다.
    for (int y = 0; y < boardY; ++y) {
        for (int x = 0; x < boardX; ++x) {
            if (hasWord(y, x, target))
                return (true);
        }
    }
    return (false);
}

int main(void) {
    int testCaseNumber;
    cin >> testCaseNumber;
    for (int testCase = 0; testCase < testCaseNumber; ++testCase) {
        for (int i = 0; i < boardY; ++i) {
            string tmpString;
            cin >> tmpString;
            board.push_back(tmpString);
        }

        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            string target;
            cin >> target;
            if (checkWord(target))
                cout << target << " YES" << endl;
            else
                cout << target << " NO" << endl;
        }

    }
}

