#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int arr[1001] = {0};
        vector<int> ans;
        vector<int>::iterator iter;
        for (iter = nums1.begin(); iter != nums1.end(); ++iter)
        {
            if (arr[*iter] == 0)
            {
                arr[*iter] += 1;
            }
        }
        for (iter = nums2.begin(); iter != nums2.end(); ++iter)
        {
            if (arr[*iter] == 1) // 避免将第二个数组中出现多次的数字也放入结果集
            {
                arr[*iter] += 1;
            }
        }
        for (int i = 0; i < 1001; ++i)
        {
            if (arr[i] >= 2)
            {
                ans.push_back(i); // 加入的应该是下标，即哈希索引
            }
        }
        return ans;
    }
};