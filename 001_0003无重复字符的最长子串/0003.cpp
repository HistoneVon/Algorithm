#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        unordered_set<char> cset;
        int left = 0; // 字符串起始位置
        int length = 0;
        int i;
        for (i = 0; i < n; ++i)
        {
            while (cset.find(s[i]) != cset.end()) // 如果新字符在已有序列中
            {
                cset.erase(s[left]); // 左侧第一个出
                ++left;
            }
            length = max(length, i - left + 1);
            cset.insert(s[i]);
        }
        return length;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcde");
    return 0;
}