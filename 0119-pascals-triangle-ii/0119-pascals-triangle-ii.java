import java.util.ArrayList;
import java.util.List;

class Solution {
    public int ncr(int n, int r, List<List<Integer>> dp) {
        if (r == 0 || r == n)
            return 1;
        if (r == 1 || r == n - 1)
            return n;
        if (dp.get(n).get(r) != -1)
            return dp.get(n).get(r);
        int result = ncr(n - 1, r, dp) + ncr(n - 1, r - 1, dp);
        dp.get(n).set(r, result);
        return result;
    }

    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>();
        List<List<Integer>> dp = new ArrayList<>();
        for (int i = 0; i <= rowIndex; i++) {
            dp.add(new ArrayList<>());
            for (int j = 0; j <= rowIndex; j++) {
                dp.get(i).add(-1);
            }
        }
        for (int i = 0; i <= rowIndex; i++) {
            ans.add(ncr(rowIndex, i, dp));
        }
        return ans;
    }
}