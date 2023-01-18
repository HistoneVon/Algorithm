#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < n; fastIndex++)
        {
            if (val != nums[fastIndex]) // 不等时，slowIndex变，fastIndex变，赋值
            {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
            // 相等时，slowIndex不变，fastIndex变，不赋值
        }
        return slowIndex; // slowIndex是目标数组最后一个元素下标+1，值上等于目标数组size
    }
};