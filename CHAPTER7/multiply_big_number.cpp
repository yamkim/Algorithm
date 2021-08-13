#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 십의 자리수는 올림을 하고, 올림된 수는 일의 자리수만 남기는 정리를 합니다.
void normalizeNumber(vector<int>& nums) {
    if (nums.empty())
        return ;
    for (int i = 0; i < nums.size(); ++i) {
        nums[i + 1] += nums[i] / 10;
        nums[i] %= 10;
    }
}

// 0번째 인덱스가 먼저 계산되므로, 321 * 654를 계산하는 결과가 됩니다.
vector<int> multiplyBigNumber(const vector<int>& a, const vector<int>& b) {
    vector<int> ret(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            ret[i + j] += a[i] * b[j];
            cout << "i: " << i << ", j: " << j << ", ret[" << i + j << "]: " << ret[i + j] << endl;
        }
    }
    normalizeNumber(ret);
    return ret;
}

int main(void) {
    string numA;
    cout << "numA: ";
    cin >> numA;
    vector<int> vecA;
    for (int i = numA.size() - 1; i >= 0; --i) {
        vecA.push_back(numA[i] - '0');
    }
    string numB;
    cout << "numB: ";
    cin >> numB;
    vector<int> vecB;
    for (int i = numB.size() - 1; i >= 0; --i) {
        vecB.push_back(numB[i] - '0');
    }

    vector<int> ans = multiplyBigNumber(vecA, vecB);

    int N = ans.size();
    for (int i = 0; i < N; ++i) {
        cout << ans[N - i - 1];
    }
    cout << endl;
}