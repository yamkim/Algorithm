#include <iostream>

using namespace std;
int count1;
int count2;

// n + (n-1) + (n-2) + ... 1
int normalSum(int n) {
    ++count1;
    if (n == 1) return 1;
    return n + normalSum(n - 1);
}

// n + (n-1) + ... n/2 + (n/2 - 1) + ... + 2 + 1
// 위의 식은 [{n ~ (n/2+1)}의 합 + {n/2 ~ 1}]의 합으로 나타낼 수 있습니다.
// {n ~ (n/2+1)}의 합은 n/2가 n/2개 있고, n/2 ~ 1이 한 번 더 있는 것과 같습니다.
// 따라서, n + ... + 1 = (n/2)*(n/2) + 2 * fastSum(n/2)입니다.

// 만약, 짝수인 경우에는 4 + 3 + 2 + 1 = 4/2 * 4/2 + 2 * (2 + 1) 이지만,
// 홀수인 경우에는 5 + 4 + 3 + 2 + 1 = 5 + (4 + 3 + 2 + 1)로 나타낼 수 있으며,
// {4 ~ 1}까지의 합은 위 방식으로 처리할 수 있습니다.
int fastSum(int n) {
    ++count2;
    if (n == 1) return 1;
    if (n % 2 == 1) return n + fastSum(n - 1);
    return n / 2 * n / 2 + 2 * fastSum(n / 2);
}

// normalSum의 경우, 16까지 더한다면 16번 normalSum을 호출합니다.
// fastSum의 경우, 16까지 더한다면 16/2 -> 8/2 -> 4/2 -> 2/2 -> 1이므로, 5번 호출합니다.
// 따라서, 분할정복으로 수행하는 경우 O(lgn)번으로 실행횟수를 줄일 수 있습니다.
int main(void) {
    count1 = 0;
    count2 = 0;
    int num = 16;
    cout << "result: " << normalSum(num) << ", count1: " << count1 << endl;
    cout << "result: " << fastSum(num)   << ", count2: " << count2 << endl;
}