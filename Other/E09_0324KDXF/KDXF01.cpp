// 100%
#include <string>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回改变后的值
     * @param num int整型 初始正整数
     * @return int整型
     */
    int changeNumber(int num) {
        // write code here
        string src = intToA(num, 2);
        int count = 0;
        int pos = -1;
        for (int i = src.size() - 1; i >= 0; --i) {
            if (src[i] == '0') {
                ++count;
            }
            if (count == 2) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            if (count == 1) {
                src = "1" + src;
            } else if (count == 0) {
                src = "10" + src;
            }
        } else {
            src[pos] = '1';
        }
        char* stop;
        return strtol(src.c_str(), &stop, 2);
    }

    string intToA(int num, int radix) {
        string res = "";
        while (num != 0) {
            int t = num % radix;
            if (t >= 0 && t <= 9) {
                res += (t + '0');
            } else {
                res += (t - 10 + 'a');
            }
            num /= radix;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};