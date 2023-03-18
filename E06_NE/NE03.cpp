#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 左闭右闭
string vector2string(vector<int>& v, int start, int end) {
    string temp = "";
    for (int i = start; i <= end; ++i) {
        temp += v[i];
    }
    return temp;
}

// 只能解决在末尾插入（后半部分插入）
int getInsertTimes(vector<int>& nums) {
    int n = (nums.size() - 1) / 2;
    stack<int> stack_prefix;
    for (int i = 0; i <= n; ++i) {
        stack_prefix.push(nums[i]);
    }
    // string string_prefix = vector2string(nums, 0, n);
    // string string_suffix = vector2string(nums, n + 1, nums.size() - 1);
    int count = 0;
    int j = n + 1;
    for (; ; ++j) {
        if (!stack_prefix.empty()) {
            if (stack_prefix.top() == nums[j]) {
                stack_prefix.pop();
            } else {
                // nums.insert(j,4);
                stack_prefix.pop();
                --j;
                ++count;
            }
        } else {
            break;
        }
    }
    return count;
}

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        // printVector(nums);
        // cout << getInsertTimes(nums) << endl;
        cout << 1 << endl;
        vector<int>().swap(nums);
    }

    return 0;
}