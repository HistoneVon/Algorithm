#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while (left <= right)
        {
            middle = (left + right) / 2; // 奇数个就是中间那个，偶数个就是中间两个较小的那个
            if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                break;
            }
        }
        if (left <= right)
        {
            return middle; // 如果退出的时候left依然小于等于right，说明是break出来的，故middle就是结果
        }
        else
        { // left > right，即并不是break出来的，证明最后一次循环中也没有匹配target
            return -1;
        }
    }
};