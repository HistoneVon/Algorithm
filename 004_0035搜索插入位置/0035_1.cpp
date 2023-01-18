// 暴力法 代码随想录思想
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size(); // 使用寄存器
        for (int i = 0; i < n; i++)
        {
            if (i == 0) // target在数组所有元素之前
            {
                if (target < nums[i])
                {
                    return 0;
                }
            }
            if (i == n-1) // target在数组所有元素之后
            {
                if (target > nums[n-1])
                {
                    return n;
                }
            }
            if (nums[i] == target) // 目标值在nums中
            {
                return i;
            }
            if (nums[i] > target) // 第一次碰到比自己大的数字就返回这个数字的下标，实际上是target插入的位置
            {
                return i;
            }
        }
        return n; // 如果循环完成都没找到就是最后一个元素之后的位置
    }
};