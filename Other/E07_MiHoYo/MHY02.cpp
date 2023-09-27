// 0.2 双指针
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s;
        string t;
        cin >> s;
        cin >> t;
        vector<char> vec;
        bool res = true;
        // 使s长于t
        if (s.size() < t.size()) {
            swap(s, t);
        }
        // 双指针fast-s slow-t
        int fast = 0;
        int slow = 0;
        for (; fast < s.size() && slow < s.size();) {
            if (s[fast] == t[slow]) {
                ++fast;
                ++slow;
            } else {
                if (s[fast] == 'm' || s[fast] == 'h' || s[fast] == 'y') {
                    vec.push_back(s[fast]);
                    ++fast;
                } else {
                    res = false; // 出现不匹配但不是mhy三个字母
                    break;
                }
            }
        }
        // 检查快慢指针是否在末尾，如果不在末尾可能是 mhy 与 abc 这种情况
        bool check_index = (fast == s.size()) && (slow == t.size());
        if (!check_index) {
            res = false;
        }
        // 检查vec中的m与h与y，是否形成连续的mhy
        if (vec.size() % 3 != 0) {
            res = false; // vec中不是3的倍数
        }
        if (res) {
            for (int j = 0; j < vec.size(); j = +3) {
                bool check_vec = (vec[j] == 'm') && (vec[j + 1] == 'h' && (vec[j + 2] == 'y'));
                if (!check_vec) {
                    res = false; // vec中不是mhy序列
                }
            }
        }
        if (res) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        vector<char>().swap(vec);
    }
    return 0;
}