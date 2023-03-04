// 优稳自动化
// 统计某个数二进制中1的个数
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int input = 5;
    unsigned n = input;
    int b;
    for (b = 0; n != 0; n >>= 1) {
        if (n & 1) {
            b++;
        }
    }
    printf("%d\n", b);
    return 0;
}