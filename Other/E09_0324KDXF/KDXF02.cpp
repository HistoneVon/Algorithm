// 0
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最短的区间长度，否则返回 -1
     * @param str string字符串
     * @return int整型
     */
    int findInterval(string str) {
        // write code here
        // 贪心
        unordered_map<int, int> umap_alphabet;
        int len = str.size(); // 字符串长
        int count = 0; // 符合标准长度
        int min = 2 * 10 ^ 5; // 最小符合标准的长度
        for (int i = 0; i < len; ++i) {
            ++umap_alphabet[str[i] - 'a']; // 加一个字母个数
            ++count;
            if (i >= 26) { // 至少26位再判断
                if (checkArray(umap_alphabet)) {
                    min = min < count ? min : count;
                    freeArray(umap_alphabet);
                    count = 0;
                }
            }
        }
        return min;
    }
    void freeArray(unordered_map<int, int>& umap) { // 清空记录数组
        for (int i = 0; i < 27; ++i) {
            umap[i] = 0;
        }
    }
    bool checkArray(unordered_map<int, int>& umap) {
        int res = true;
        int count = umap[26]; // 问号的个数
        for (int i = 0; i < 26; ++i) { // 对字母部分的检查
            if (umap[i] == 0) {
                --count;
            }
        }
        if (count <= 0) { // 如果问号的个数未超过空白字母的个数
            res = false;
        }
        return res;
    }
};