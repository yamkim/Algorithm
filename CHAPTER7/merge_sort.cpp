#include <iostream>
#include <vector>

using namespace std;

// 이미 정렬되어있는 두 벡터가 주어지는 경우, O(n)의 시간복잡도로 정렬합니다.
vector<int> sortTwoVectors(vector<int>& arr1, vector<int>& arr2) {
    if (arr1.empty())
        return arr2;
    if (arr2.empty())
        return arr1;

    vector<int> ret;
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < arr1.size() && idx2 < arr2.size()) {
        if (arr1[idx1] > arr2[idx2]) {
            ret.push_back(arr2[idx2]);
            ++idx2;
        } else {
            ret.push_back(arr1[idx1]);
            ++idx1;
        }
    }
    if (idx1 == arr1.size()) {
        for (int i = idx2; i < arr2.size(); ++i)
            ret.push_back(arr2[i]);
    } else {
        for (int i = idx1; i < arr1.size(); ++i)
            ret.push_back(arr1[i]);
    }
    return ret;
}

vector<int> nums;
int N;

vector<int> solve(int left, int right) {
    vector<int> ret;
    // left가 right랑 같은 경우, 하나까지 분할이 완료된 상태이므로, 하나의 값만 반환합니다.
    if (left == right) {
        ret.push_back(nums[left]);
        return ret;
    }
    // 중간 값을 구하고, [left, middle], [middle, right]로 구간을 나눕니다.
    int middle = (right + left) / 2;
    vector<int> part1 = solve(left, middle);
    vector<int> part2 = solve(middle + 1, right);
    // 위 각각의 벡터가 나올 때, 이를 합하면서 정렬하는 구문을 실행시킵니다.
    ret = sortTwoVectors(part1, part2);
    return ret;
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    vector<int> ans = solve(0, N - 1);
    cout << "Sorted result ================" << endl;
    for (int i = 0; i < N; ++i)
        cout << ans[i] << " ";
}