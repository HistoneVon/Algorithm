// 0.8571
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
            } else if (str[i] == '?') {
                if (str[i - 1] == '0') {
                    str[i] = '1';
                } else if (str[i - 1] == '1') {
                    str[i] = '0';
                }
                ++count;
            }
        }
        return count;
    }
};