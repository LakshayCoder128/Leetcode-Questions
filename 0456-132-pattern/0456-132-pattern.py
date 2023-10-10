class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        least = float('-inf')
        st = []

        for i in range(len(nums) - 1, -1, -1):
            if nums[i] < least:
                return True
            while st and nums[i] > st[-1]:
                least = st.pop()
            st.append(nums[i])

        return False