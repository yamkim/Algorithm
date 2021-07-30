#include <iostream>
#include <vector>

using namespace std;

int H, W;

// 빈 칸을 채우기 위한 블록타입을 지정합니다.
// ㄴ자 블록으로, 위에서부터 채워 내려오는 방식으로 코딩하므로,
// 위로 올라가지 않는 모양만 선정합니다.
const int coverType[4][3][2] = {
    { {0, 0}, {1, 0}, {1, 1} },
    { {0, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, 0}, {0, 1} },
    { {0, 0}, {1, 0}, {1, -1} }
};

void showBoard(vector<vector<int> >& board) {
    cout << "BOARD ==============" << endl;
    for (int j = 0; j < H; ++j) {
        for (int i = 0; i < W; ++i) {
            cout << board[j][i];
        }
        cout << endl;
    }
    cout << "====================" << endl;
}

void findEmptyYX(vector<vector<int> >& board, int& y, int& x) {
    for (int j = 0; j < H; ++j) {
        for (int i = 0; i < W; ++i) {
            if (board[j][i] == 0) {
                y = j;
                x = i;
                return ;
            }
        }
        // 이중루프이므로 안에서 탈출했으면 여기서도 탈출해야합니다.
        // board[j][i]를 쭉 돌았는데, y = -1이라면, 모두 꽉 차있다는 의미가 됩니다.
        if (y != -1) return;
    }
}

bool inRange(int y, int x) {
    if (y >= H || y < 0 || x >= W || x < 0) return false;
    return true;
}

bool set(vector<vector<int> >& board, int y, int x, int type, int delta) {
    // - block type 한 세트는 세 칸이므로, 세칸에 대해 모두 비어있어서,
    //   그 칸을 해당 타입으로 덮을 수 있는지 확인합니다.
    // - 어떻게 됐든, 일단 type 한 세트에 대해 수행을 해봐야하므로,
    //   중간에 리턴하지 않기 위해 플래그를 둡니다.
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if (!inRange(ny, nx))
            ok = false;
        // range는 포함되지만, 겹쳐서 놓는 경우에는 false입니다.
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return (ok);
}

int cover(vector<vector<int> >& board) {
    int y = -1;
    int x = -1;
    findEmptyYX(board, y, x);
    // 블록을 모두 채운 케이스로, 성공 케이스 카운트를 1 올립니다.
    if (y == -1) return 1;
    int ret = 0;
    for (int type = 0; type < 4; ++type) {
        // 일단 해당 타입으로 덮어본 후, 성공하면 카운트를 증가시킵니다.
        if (set(board, y, x, type, 1)) {
            ret += cover(board);
            // board의 변화를 실시간으로 봅니다.
            // showBoard(board);
        }
        // 만약, 실패한다면, 새로운 타입으로 테스트 하기 위해
        // 현재 타입의 블록을 제거합니다. 
        set(board, y, x, type, -1);
    }
    return (ret);
}

int main(void) {
    int testCaseNbr;
    cin >> testCaseNbr;
    for (int testCase = 0; testCase < testCaseNbr; ++testCase) {
        vector<vector<int> > board;
        cin >> H >> W;
        board.resize(H, vector<int>(W, 0));
        for (int i = 0; i < H; ++i) {
            string tmpStr;
            cin >> tmpStr;
            for (int j = 0; j < W; ++j) {
                // #이면 채워져있다는 의미로 1을, .이면 비어있다는 의미로 0을 할당합니다.
                int tmpVal = tmpStr[j] == '#' ? 1 : 0;
                board[i][j] = tmpVal;
            }
        }
        cout << cover(board) << endl;
    }
    return (0);
}