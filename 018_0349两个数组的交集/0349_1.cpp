#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> res_set;
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for (auto num : nums2)
        {
            if (num_set.find(num) != num_set.end())
            {
                res_set.insert(num);
            }
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};