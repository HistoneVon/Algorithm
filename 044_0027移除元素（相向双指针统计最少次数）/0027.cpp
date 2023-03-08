/**
 * @file 0027.cpp
 * @author Histone Von (fengclchn@outlook.com)
 * @brief 移除元素（相向双指针法，可以统计最少移动次数，不保证原始次序）
 * @version 0.1
 * @date 2023-03-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int left = 0;
    int right = nums.size() - 1;
    int count = 0; // 移动次数
    while (left <= right) {
        while (left <= right && nums[left] != val) {
            ++left;
        }
        while (left <= right && nums[right] == val) {
            --right;
        }
        if (left < right) {
            // 这里一定要有left<right
            // 可以有两个理解：
            // 1.如果换那么left一定是小于right的，并且不可能是等于（等于没有意义）
            // 2.当以上造成left>=right时，不要再多此一举给left++或给right--
            nums[left++] = nums[right--];
            ++count;
        }
    }
    cout << count << endl;
    return left;
}

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int n; // 输入数组元素个数
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    int val;
    cin >> val; // 要删除的数字
    removeElement(vec, val);
    printVector(vec);
    return 0;
}