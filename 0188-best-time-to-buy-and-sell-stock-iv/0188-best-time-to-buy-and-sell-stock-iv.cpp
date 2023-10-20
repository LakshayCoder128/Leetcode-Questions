class Solution {
public:
    int maxProfit(int maxTransactions, vector<int>& prices) {
        int n = prices.size();
        // if (n <= 1 || maxTransactions <= 0) {
        //     return 0;
        // }

        // Create a 2D array to store the maximum profit.
        vector<vector<int>> maxProfit(n, vector<int>(maxTransactions + 1, 0));

        for (int transaction = 1; transaction <= maxTransactions; transaction++) {
            int maxDiff = -prices[0];
            for (int day = 1; day < n; day++) {
                // Calculate the maximum profit for the current day and transaction.
                maxProfit[day][transaction] = max(maxProfit[day - 1][transaction], prices[day] + maxDiff);
                // Update the maximum difference for the current day.
                maxDiff = max(maxDiff, maxProfit[day - 1][transaction - 1] - prices[day]);
            }
        }

        return maxProfit[n - 1][maxTransactions];
    }
};
