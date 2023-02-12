#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); ++k)
        {
            // 剪枝
            // 如果当前值为正数，并且大于target，那么就一定再没有符合的值
            // 负数不一定，当前值为负并大于target，以后的值加进来还会造成总和降低
            if (nums[k] > target && nums[k] >= 0)
            {
                break; // 统一最后返回，不单独return
            }
            // 去重nums[k]
            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }
            for (int i = k + 1; i < nums.size(); ++i)
            {
                // 2级剪枝，理由同上
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
                {
                    break;
                }
                // 去重nums[i]
                if (i > k + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    // 不加long会溢出
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 去nums[left] nums[right]
                        // 如果right当前值与right前一位相等，则持续right--，相当于跳过前一值
                        while (right > left && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        // 如果left当前值与left后一位相等，则持续left++，相当于跳过后一值
                        while (right > left && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        // 找到答案，双指针同时收缩
                        // 因为跳过了重复值，所以收缩后的值一定是不重复的
                        // 这样下一轮循环中的可能的结果集一定是不同的
                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};