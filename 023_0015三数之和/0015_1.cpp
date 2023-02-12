// 双指针法
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); ++i)
        {
            // 排序之后如果第一个元素已经大于0，那么无论如何都不可能凑成三元组，直接返回结果
            // 无论哪一轮循环都适用于此规则
            if (nums[i] > 0)
            {
                return res;
            }
            // 去重a
            // 不能使用nums[i] == nums[i+1]，因为如果left=i+1相当于在判断结果集中的元素是否相等，但这种情况允许存在，如{-1, -1, 2}
            // 换个角度，我认为一定是判断当前这个元素nums[i]之前是否出现过，而不是判断当前这个元素会不会在未来出现
            // 另外，防止数组下标出现负数，一定要加上i>0这个条件
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            // 循环条件不能是right>=left，这样的话bc就是一个数，不再是三元组，不符合条件
            while (right > left)
            {
                // 如果去重bc逻辑放在这里会导致错过可能得结果集，举例{0,0,0,0,0}
                // 一定要在找到一个可能的结果集后再进行去重
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    // =0，收割结果
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重的逻辑一定要放在至少收获一个结果后，不然可能会跳过可能得结果集，举例{0,0,0,0,0}
                    // b c去重，举例{0,-1,-1,-1,-1,1,1,1,1}
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
        return res;
    }
};