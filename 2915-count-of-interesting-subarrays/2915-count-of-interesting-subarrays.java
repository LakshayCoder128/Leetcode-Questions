class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
         int n = nums.size();
        long[] ps = new long[n + 1];
        Map<Long, Long> frq = new HashMap<>();

        ps[0] = 0;
        frq.put(0L, 1L);
        long ans = 0;

        for (int i = 0; i < n; i++) {
            ps[i + 1] = (ps[i] + (nums.get(i) % modulo == k ? 1 : 

0)) % modulo;
            long xp = (ps[i + 1] - k + modulo) % modulo;
            ans += frq.getOrDefault(xp, 0L);
            frq.put(ps[i + 1], frq.getOrDefault(ps[i + 1], 0L) + 1);
        }

        return ans;
    }
}