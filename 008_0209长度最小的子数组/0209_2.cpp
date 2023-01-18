// 华栋窗口 自己的理解
#include<limits>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(); // nums长度
        int ans = INT32_MAX; // 结果值
        int sum = 0; // 子序列和
        int len = 0; // 子序列长度
        int i = 0, j = 0; // i是子序列头下标，j是子序列尾下标
        for (; j < n;) { // 尾下标不能超过n-1
            sum += nums[j]; // 尾下标向后移动一位，sum+尾
            if (sum >= target) {
                if (i == j) { // 如果i和j相等，说明就一个数字即可满足，其余都不用判断了
                    return 1;
                }
                len = j - i + 1;
                ans = ans < len ? ans : len;
                for (; i <= j;) { // 先减去原值，i初始值不用加1；
                    // ij等于（=）合法的原因：如果i=j且大于target，那么下一次的大循环中是不能再出现这一个数字的
                    // 且sum会被减为0，必然过不了sum>=target的判断，因为题目中target大于等于1
                    // 应该可以优化，i=j时直接return 1；见上第17行
                    sum -= nums[i]; // 头下标向后移动一位，sum-头
                    ++i; // 符合条件后，头下标要每次向后移动一位，以便测出最小len
                    // 以上两句可以合成sum -= nums[i++]
                    if (sum >= target) {
                        len = j - i + 1; // 使用新的i计算新的len
                        ans = ans < len ? ans : len;
                    } else {
                        break; // 如果第一次碰到小于target的就不要继续循环了，保留当前状态退出头下标循环
                    }
                }
            }
            ++j; //每次都需要j向后移动一位
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};