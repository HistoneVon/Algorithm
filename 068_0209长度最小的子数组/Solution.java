// 滑动窗口

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int size = nums.length;
        int left = 0;
        int right = 0;
        int res = Integer.MAX_VALUE;
        int len = 0;
        int sum = 0;
        while (right < size) {
            sum += nums[right];
            if (sum >= target) {
                len = right - left + 1;
                res = len < res ? len : res;
                while (left <= right) {
                    sum -= nums[left];
                    ++left;
                    if (sum >= target) {
                        len = right - left + 1;
                        res = len < res ? len : res;
                    } else {
                        break;
                    }
                }
            }
            ++right;
        }
        return res == Integer.MAX_VALUE ? 0 : res;
    }
}