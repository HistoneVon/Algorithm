// 0.0714
// 小红的01问号串 相邻不同对
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return int整型
     */
    int maxDifferentPairs(string str) {
        // write code here
        // 前缀?处理
        int count = 0; // 相邻不同对个数
        int k = 0;
        for (;;) {
            if (str[k] == '?') {
                ++k;
            } else {
                break;
            }
        }
        count += k;
        // 从第二个非?字符开始，可以直接进行比较
        for (int i = k + 1; i < str.size(); ++i) {
            if (str[i] != '?' && str[i] != str[i - 1]) {
                ++count;
            } else if (str[i] != '?' && str[i] == str[i - 1]) {
                continue;
            } else if (str[i] == '?') { // 负责找到下一个非?
                int pre = i - 1; // 前面的非?
                int j = 0; // 临时计数器，统计中间的?
                while (i < str.size())
                {
                    if (str[i] == '?') {
                        ++j;
                    } else {
                        break;
                    }
                    ++i;
                }
                int suf = i; // 后面的非?
                int c = suf - pre - 1; // 问号个数
                if (str[pre] == str[suf]) {
                    count += c;
                } else {
                    if (c % 2 == 0) {
                        count += (c+1);
                    } else {
                        count += c;
                    }
                }
                ++i; // 越过?后的第一个数字，因为已经判断过，这句注释掉是0.1429
            }
        }
        return count;
    }
};