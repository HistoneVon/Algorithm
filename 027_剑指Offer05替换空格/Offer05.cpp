#include <string>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        // 统计空格个数
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < oldSize; ++i)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }
        // 扩充字符串长度
        s.resize(oldSize + count * 2);
        int newSize = s.size();
        // 从后向前替换
        for (int i = newSize - 1, j = oldSize - 1; j < i; --i, --j)
        {
            if (s[j] != ' ')
            {
                s[i] = s[j];
            }
            else
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};