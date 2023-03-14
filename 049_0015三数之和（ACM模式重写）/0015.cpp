#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        // 找到i
        if (nums[i] > 0) {
            return res;
        }
        // 去重i
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (right > left) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                // 找到b c
                int temp[] = { nums[i], nums[left], nums[right] };
                res.push_back(vector<int>(temp, temp + 3));
                // 去重b c
                while (right > left && nums[right] == nums[right - 1]) {
                    right--;
                }
                while (right > left && nums[left] == nums[left + 1]) {
                    left++;
                }
                // 偏移left right，为下一轮循环准备
                left++;
                right--;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums;
    vector<vector<int> > res;
    int n;
    while (cin >> n) {
        nums.push_back(n);
        if (cin.get() == '\n') {
            res = threeSum(nums);
            cout << "[";
            for (int i = 0; i < res.size(); ++i) {
                cout << "[";
                for (int j = 0; j < 3; ++j) {
                    cout << res[i][j];
                    if (j != 2) {
                        cout << ",";
                    }
                }
                cout << "]";
                if (i != res.size() - 1) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
            vector<vector<int> >().swap(res);
            vector<int>().swap(nums);
        }
    }
    return 0;
}