// ac: 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count1;

void printVector(vector<int>& nums) {
    for (int i = 0;i < nums.size();++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void quickSort(vector<int>& nums, int begin, int end) {
    if (begin > end) {
        return;
    }
    int temp = nums[begin];
    int i = begin;
    int j = end;
    while (i != j) {
        while (nums[j] >= temp && j > i) {
            --j;
        }
        while (nums[i] <= temp && j > i) {
            ++i;
        }
        if (j > i) {
            swap(nums[i], nums[j]);
            count1++;
        }
    }
    nums[begin] = nums[i];
    nums[i] = temp;
    quickSort(nums, begin, i - 1);
    quickSort(nums, i + 1, end);
}

int main() {
    int n, m;
    count1 = 0;
    vector<int> nums;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> m;
            nums.push_back(m);
        }
        // printVector(nums);
        quickSort(nums, 0, nums.size() - 1);
        // printVector(nums);
        swap(nums[0], nums[1]);
        // printVector(nums);
        cout << count1 << endl;
        vector<int>().swap(nums);
    }
    return 0;
}