// 哈希法
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                break; // 排序后如果第一个元素已经大于零，那么不可能凑成三元组
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue; // 三元组元素a去重
            }
            unordered_set<int> uset;
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 2 && nums[j] == nums[j - 1 && nums[j - 1] == nums[j - 2]])
                {
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (uset.find(c) != uset.end())
                {
                    res.push_back({nums[i], nums[j], c});
                    uset.erase(c); // c去重
                }
                else
                {
                    uset.insert(nums[j]);
                }
            }
        }
        return res;
    }
};