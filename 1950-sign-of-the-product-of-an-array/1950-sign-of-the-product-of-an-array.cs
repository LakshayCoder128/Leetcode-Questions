public class Solution {
    public int ArraySign(int[] nums) {
        int countNeg = 0;
        int countZero = 0;

        foreach (int num in nums) {
            if (num < 0) {
                countNeg--;
            } else if (num == 0) {
                countZero++;
            }
        }

        if (countZero >= 1) {
            return 0;
        }

        return countNeg % 2 == 0 ? 1 : -1;
    }
}