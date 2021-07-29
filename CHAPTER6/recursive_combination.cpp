#include <iostream>
#include <vector>

using namespace std;

void printPicked(vector<int> picked) {
    for(int i = 0; i < picked.size(); ++i) {
        cout << picked[i] << " ";
    }
    cout << endl;
}

// NOTE: 조합 구현함수.
// 만약, a, b, c, d가 있다면 [a, b], [a, c], [a, d], [b, c] ...
// 가장 먼저 a를 뽑은 후, 다음 깊이에서 b, c, d를 고르는 방식입니다.
// 만약 b가 뽑힌다면 그 다음 깊이는 pickCount가 0이 되므로 탈출합니다.
int N;
int M;
void pick(int n, vector<int>& picked, int pickCount) {
    // base case: 정해진 수만큼 pick을 완료 하였을 때
    if (pickCount == 0) {
        printPicked(picked);
        return ;
    } 
    // 책에서는 아래와 같이 몇번째 인덱스부터 시작할지 설정합니다. 
    // int smallest = picked.empty() ? 0 : picked.back() + 1;
    // for (int next = smallest; next < N; ++next)

    // N은 nCm의 n으로, 후보군 전체의 개수를 의미합니다.
    for (int next = n; next < N; ++next) {
        // a가 뽑힌 경우, 
        picked.push_back(next);
        // 이번 숫자를 뽑았으면, 그 다음 수부터 뽑아야하므로
        pick(next + 1, picked, pickCount - 1);
        // 위에서 pickCount를 모두 사용하고 
        picked.pop_back();
    }
}

int main(void) {
    // nCm에 맞게 각각을 대입합니다.
    N = 5;
    M = 3;
    vector<int> picked;
    pick(0, picked, M);
}