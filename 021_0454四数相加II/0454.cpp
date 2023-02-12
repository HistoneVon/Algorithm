#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> umap;
        for (auto a : nums1)
        {
            for (auto b : nums2)
            {
                umap[a + b]++;
            }
        }
        int count = 0;
        for (auto c : nums3)
        {
            for (auto d : nums4)
            {
                if (umap.find(0 - (c + d)) != umap.end())
                {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};