class Solution:
    def arraySign(self, nums: List[int]) -> int:
        count_neg = 0
        count_zero = 0

        for num in nums:
            if num < 0:
                count_neg -= 1
            elif num == 0:
                count_zero += 1

        if count_zero >= 1:
            return 0

        return 1 if count_neg % 2 == 0 else -1