#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int rec[26] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            ++rec[s[i] - 'a'];
        }
        for (int i = 0; i < t.size(); ++i)
        {
            --rec[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i)
        {
            if (rec[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};