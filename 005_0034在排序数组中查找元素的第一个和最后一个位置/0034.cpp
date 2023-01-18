#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size();
        int start = -1;
        int end = -1;
        for (int i = 0; i < n; i++)
        {
            if (start == -1 && nums[i] == target)
            {
                start = i;
                continue; // 直接进入下轮循环，防止start确定后再次进入下一个判断
            }
            if (start != -1 && nums[i] > target)
            {
                end = i - 1;
                break; // 防止重复判断start != -1的情况，因为只要是确认了开头，后边每个大于target的元素都符合，也可以直接在判断中写明end==-1
            }
        }
        if (n == 1 && start != -1 && end == -1) // 解决仅有一个数组元素的情况
        {
            end = start;
        }
        if (n > 1 && start != -1 && end == -1) // 解决大于一个元素并且从中间某一元素至末尾都等于target的情况（没有大于target的元素供设置end）
        {
            end = n - 1;
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    Solution S;
    vector<int> ANS = S.searchRange(A, 1);
    cout << "[" << ANS[0] << "," << ANS[1] << "]" << endl;
}