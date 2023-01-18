// 双指针法
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int k = n - 1;
        vector<int> ans(n, -1);
        for (; i <= j;) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                ans[k--] = nums[j] * nums[j];
                j--;
            } else {
                ans[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return ans;
    }
};