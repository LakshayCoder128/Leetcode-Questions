class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        n = len(nums)
        ps = [0] * (n + 1)
        frq = {}

        ps[0] = 0
        frq[0] = 1
        ans = 0

        for i in range(n):
            ps[i + 1] = (ps[i] + (nums[i] % modulo == k)) % modulo
            xp = (ps[i + 1] - k + modulo) % modulo
            ans += frq.get(xp, 0)
            frq[ps[i + 1]] = frq.get(ps[i + 1], 0) + 1

        return ans