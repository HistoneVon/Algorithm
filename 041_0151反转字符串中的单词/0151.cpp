#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void removeExtraSpaces(string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') { // 排除所有空格，是每个单词前的空格（每个单词处理一次）
                if (slow != 0) { // 如果slow不是第一个单词，那么给这个单词前添加一个空格
                    s[slow] = ' ';
                    ++slow;
                }
                while (i < s.size() && s[i] != ' ') { // 复制新一个单词，直到遇到空格
                    s[slow] = s[i];
                    ++slow;
                    ++i;
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小
    }

    void reverseStr(string& s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); // 去除多余空格
        reverseStr(s, 0, s.size() - 1); // 整体反转字符串
        // 逐个反转单词
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || ' ' == s[i]) {
                reverseStr(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};