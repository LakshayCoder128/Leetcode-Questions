class Solution {
    public boolean find132pattern(int[] nums) {
        int least = Integer.MIN_VALUE;
        Stack<Integer> stack = new Stack<>();

        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] < least) return true;
            while (!stack.isEmpty() && nums[i] > stack.peek()) {
                least = stack.pop();
            }
            stack.push(nums[i]);
        }

        return false;
    }
}