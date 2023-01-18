// 二分法改进 代码随想录思想
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int middle;
        if (target > nums[right])
        {
            return n;
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
            }
        }
        // target不在nums中
        return left; // 因为right永远在left的左边一个，所以永远只需要返回left（right+1）即可
    }
};