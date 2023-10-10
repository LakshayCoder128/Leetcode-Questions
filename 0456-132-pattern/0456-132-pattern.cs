public class Solution {
    public bool Find132pattern(int[] nums) {
        int least = int.MinValue;
        Stack<int> st = new Stack<int>();

        for (int i = nums.Length - 1; i >= 0; i--) {
            if (nums[i] < least) return true;
            while (st.Count > 0 && nums[i] > st.Peek()) {
                least = st.Pop();
            }
            st.Push(nums[i]);
        }

        return false;
    }
}