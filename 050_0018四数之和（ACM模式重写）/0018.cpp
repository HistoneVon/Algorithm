#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        // 找到i，剪枝i
        if (nums[i] > target && nums[i] >= 0) {
            break;
        }
        // 去重i
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < nums.size(); ++j) {
            // 找到j，剪枝j
            if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                break;
            }
            // 去重j
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            int left = j + 1;
            int right = nums.size() - 1;
            while (right > left) {
                if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                    right--;
                } else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                    left++;
                } else {
                    // 找到c d
                    int temp[] = { nums[i],nums[j],nums[left],nums[right] };
                    res.push_back(vector<int>(temp, temp + 4));
                    // 去重c d
                    while (right > left && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // 偏移，为下一轮准备
                    left++;
                    right--;

                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums;
    vector<vector<int> > res;
    int a;
    int target;
    while (cin >> a) {
        nums.push_back(a);
        if (cin.get() == '\n') {
            cin >> target;
            res = fourSum(nums, target);
            cout << "[";
            for (int i = 0; i < res.size(); ++i) {
                cout << "[";
                for (int j = 0; j < res[i].size(); ++j) {
                    cout << res[i][j];
                    if (j != res[i].size() - 1) {
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