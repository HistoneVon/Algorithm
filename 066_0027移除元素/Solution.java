// 快慢指针法

class Solution {
    public int removeElement(int[] nums, int val) {
        int slow = 0;
        int fast = 0;
        for (; fast < nums.length;) {
            if (val != nums[fast]) {
                nums[slow] = nums[fast]; // nums[fast]不是val的才赋值给nums[slow]
                ++slow; // slow碰到nums[fast]不是val的才++
            }
            ++fast; // fast永远++
        }
        return slow;
    }
}