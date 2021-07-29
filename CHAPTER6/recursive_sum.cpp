#include <iostream>

using namespace std;

int recursiveSum(int n) {
    // 재귀함수 기저사례(base case) 세팅
    if (n <= 1) return 1;
    return (n + recursiveSum(n - 1));
}

int main(void) {
    std::cout << recursiveSum(10);
}