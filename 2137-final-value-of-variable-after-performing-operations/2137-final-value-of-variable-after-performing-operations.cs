public class Solution {
    public int FinalValueAfterOperations(string[] operations) {
        int ans = 0;
        foreach (string operation in operations) {
            if (operation == "--X" || operation == "X--") {
                ans--;
            } else if (operation == "++X" || operation == "X++") {
                ans++;
            }
        }
        return ans;
    }
}