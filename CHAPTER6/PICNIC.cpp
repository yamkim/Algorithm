#include <iostream>
#include <vector>


using namespace std;
const int FRIEND_NUMBER = 10;
bool areFriends[FRIEND_NUMBER][FRIEND_NUMBER];
int N, M;

int findFirstFree(bool taken[FRIEND_NUMBER]) {
    int ret = -1;
    for (int i = 0; i < N; ++i) {
        if (!taken[i])
            return (i);
    }
    return (ret);
}

int countPairs(bool taken[FRIEND_NUMBER]) {
    // 모든 학생이 매칭된 경우, 성공이므로 카운트 합니다.
    int firstFree = -1;
    if ((firstFree = findFirstFree(taken)) == -1)
        return (1);
    int ret = 0;
    // firstFree 다음 친구부터 firstFree와 친구인지 카운트합니다.
    // 이를 위해, areFriends를 대칭 행렬로 만들어줍니다.
    // (아래와 같다면 [3][0]은 카운트하지 않을 것이기 때문에, [3][0] = [0][3]이 되도록)
    for (int pairWith = firstFree + 1; pairWith < N; ++pairWith) {
        if (!taken[firstFree] && !taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = true;
            taken[pairWith] = true;
            // firstFree, pairWith 번째 친구를 짝으로 만들어 본 후 진행해봅니다.
            ret += countPairs(taken);
            // 만약, firstFree와 pairWIth 번째 친구가 짝이 된 상태로 진행결과 모두 매칭이 된다면,
            // ret에 1이 더해졌을 것이고, 그렇지 않다면 0이 더해졌을 것입니다.
            // 다음 진행을 위해 true로 만들어두었던 각각을 false로 합니다.
            taken[firstFree] = false;
            taken[pairWith] = false;
        }
    }
    // 루프를 돌며 매칭해봤지만, 매칭이 되지 않는 경우 0이 반환됩니다.
    // 루프를 돌며 여러번의 매칭 가능성이 있으면 ret이 그만큼 증가되어 반환됩니다.
    return (ret);
}

void debugAreFriendsInput() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << areFriends[i][j];
        }
        cout << endl;
    }
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int friend1;
        int friend2; 
        cin >> friend1 >> friend2;
        areFriends[friend1][friend2] = true;
        areFriends[friend2][friend1] = true;
    }
    // debugAreFriendsInput();
    bool taken[FRIEND_NUMBER] = { false, };
    cout << countPairs(taken) << endl;

}