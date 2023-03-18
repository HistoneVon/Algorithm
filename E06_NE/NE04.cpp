// 0.7273
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double getAverage(vector<int>& v) {
    if (v.size() == 0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return 1.0 * sum / v.size();
}

int getSum(vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}

int isAverage(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> A;
    vector<int> B;
    int i = nums.size() - 1;
    A.push_back(nums[i--]);
    // B.push_back(nums[i--]);
    for (; i >= 0; --i) {
        if (getSum(B) < getSum(A)) {
            B.push_back(nums[i]);
        } else if (getSum(A) < getSum(B)) {
            A.push_back(nums[i]);
        } else {
            A.push_back(nums[i]); // 策略1：直接给A或B
            // 策略2：给数字多的那一个
        }
    }
    if (getAverage(A) == getAverage(B)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
        if (cin.get() == '\n') {
            cout << isAverage(nums) << endl;
            vector<int>().swap(nums);
        }
    }

    return 0;
}