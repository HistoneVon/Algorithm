#include <vector>
#include <deque>
using namespace std;

class slidingWindow {
public:
    deque<int> que; // deque实现单调队列

    void pop(int value) {
        // 队列非空，且如果队头元素等于当前要弹出的元素，则弹出
        if (!que.empty() && que.front() == value) {
            que.pop_front();
        }
    }

    void push(int value) {
        // 如果要push的值大于队尾元素，则弹出队尾，直到push的值小于等于队尾元素
        // 保证队列中是递减的
        while (!que.empty() && value > que.back()) {
            que.pop_back();
        }
        que.push_back(value);
    }

    int front() {
        // 当前队列中最大值就是队头值
        return que.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        slidingWindow sw;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            sw.push(nums[i]); // 首先把前k个数字放入华栋窗口
        }
        res.push_back(sw.front()); // 求前k个数字的最大值
        for (int i = k; i < nums.size(); ++i) {
            sw.pop(nums[i - k]); // 先弹出窗口左侧的数字（如果符合就弹出）
            sw.push(nums[i]); // 压入当前数字
            res.push_back(sw.front()); // 求新的窗口的最大值
        }
        return res;
    }
};