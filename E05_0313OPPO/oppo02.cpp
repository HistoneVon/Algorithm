#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * findStr从反方向查找子串，返回最后一次匹配成功时，子串的偏移位置，如果没有匹配成功返回-1
     * @param str string字符串 待匹配的字符串
     * @param mod string字符串 匹配模式字符串
     * @return int整型
     */
    int findStr(string str, string mod) {
        // write code here
        if (mod.find("*") == -1) { // 无通配符
            reverse(mod.begin(), mod.end());
            int start = str.find(mod);
            int res = start + mod.size() - 1;
            return res;
        } else { // 有通配符，字母＋通配符（其实应该是dp）
            int pos_universe = mod.find("*");
            cout << pos_universe << endl;
            string mod_letter = mod.substr(0, pos_universe);
            cout << mod_letter << endl;
            reverse(mod_letter.begin(), mod_letter.end());
            cout << mod_letter << endl;
            int start = str.find(mod_letter);
            int res = start + mod_letter.size() - 1;
            return res;
        }
    }
};