#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/**
 * @brief 全排列（左闭右闭区间）
 *
 *
 * @param a 数组
 * @param p 需要全排列的左边界
 * @param q 需要全排列的右边界
 */
void perm(int a[], int p, int q) {
    if (p == q) { // 终止条件：对一个元素进行全排列的时候打印输出
        printArray(a, q + 1);
    } else { // 全排列核心代码
        for (int i = p; i <= q; ++i) {
            swap(a[i], a[p]);
            perm(a, p + 1, q);
            swap(a[i], a[p]);
        }
    }
}

int main() {
    int a[6] = { 0,1,2 };
    perm(a, 0, 2);
    return 0;
}