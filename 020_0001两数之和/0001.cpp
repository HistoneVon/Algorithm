#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int,int>::iterator iter = umap.find(target - nums[i]);
            if (iter != umap.end()) {
                return {iter->second, i};
            }
            umap.insert(pair<int,int>(nums[i], i));
        }
        return vector<int>();
    }
};