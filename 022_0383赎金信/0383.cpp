#include <string>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int rec[26] = {0};
        for (int i = 0; i < ransomNote.size(); ++i)
        {
            rec[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.size(); ++i)
        {
            rec[magazine[i] - 'a']--;
        }
        for (int r : rec)
        {
            if (r > 0)
            {
                return false; // 如果找到了一个字母magazine未满足ransomNote则false
            }
        }
        return true; // 如果均满足则返回true，包括超过（即rec中为负的情况）
    }
};