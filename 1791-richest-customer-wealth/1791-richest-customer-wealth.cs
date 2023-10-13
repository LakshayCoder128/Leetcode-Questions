public class Solution {
    public int MaximumWealth(int[][] accounts) {
        int maxWealth = 0;
        foreach (var customer in accounts) {
            int wealth = customer.Sum();
            maxWealth = Math.Max(maxWealth, wealth);
        }
        return maxWealth;
    }
}