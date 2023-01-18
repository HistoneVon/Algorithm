// 暴力法 双重循环 超时
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
        for (int i = 0; i < n; ++i) { // i是子序列头下标
            sum = 0;
            for (int j = i; j < n; ++j) { // j是子序列尾下标
                sum += nums[j];
                if (sum >= target) {
                    len = j - i + 1;
                    ans = ans < len ? ans : len;
                    break;
                }
            }
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};