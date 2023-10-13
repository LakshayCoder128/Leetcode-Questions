class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;
        for (String operation : operations) {
            if (operation.equals("--X") || operation.equals("X--")) {
                ans--;
            } else if (operation.equals("++X") || operation.equals("X++")) {
                ans++;
            }
        }
        return ans;
    }
}