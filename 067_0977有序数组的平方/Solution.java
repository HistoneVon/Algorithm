// 自己的思路

class Solution {
    public int[] sortedSquares(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        int[] result = new int[nums.length];
        int n = nums.length - 1;
        while (left <= right) {
            int l = (int) Math.pow(nums[left], 2);
            int r = (int) Math.pow(nums[right], 2);
            if (l <= r) {
                result[n--] = r;
                --right;
            } else if (l > r) {
                result[n--] = l;
                ++left;
            }
        }
        return result;
    }
}