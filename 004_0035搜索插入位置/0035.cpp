// 原始提交
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        if (target > nums[right])
        {
            return right + 1;
        }
        if (target < nums[left])
        {
            return 0;
        }
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                return middle; // target在nums中，在此程序中可换为break
                // break;
            }
        }
        // target不在nums中
        if (nums[middle] > target)
        {
            return right;
        }
        else if (nums[middle] < target)
        {
            return left;
        }
        else
        {
            return middle; // target在nums中
        }
    }
};