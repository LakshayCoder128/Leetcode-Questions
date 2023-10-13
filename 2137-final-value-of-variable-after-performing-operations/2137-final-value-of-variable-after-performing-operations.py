class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        ans = 0
        for operation in operations:
            if operation == "--X" or operation == "X--":
                ans -= 1
            elif operation == "++X" or operation == "X++":
                ans += 1
        return ans
    