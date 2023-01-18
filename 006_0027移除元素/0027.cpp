#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int i, j;
        for (i = 0; i < n; i++)
        {
            if (nums[i] == val)
            {
                for (j = i; j < n - 1; j++)
                {
                    nums[j] = nums[j + 1];
                }
                n -= 1;
                i -= 1;//指针回退一个，被删除的元素的下一个元素占据了被删元素的下标，i若不变会越过该元素
            }
        }
        return n;
    }
};