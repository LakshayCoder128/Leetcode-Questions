class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        dp = {}
        
        def isScrambleHelper(s1: str, s2: str) -> bool:
            if s1 == s2:
                return True
            if (s1, s2) in dp:
                return dp[(s1, s2)]
            
            if sorted(s1) != sorted(s2):
                dp[(s1, s2)] = False
                return False
            
            for i in range(1, len(s1)):
                if (isScrambleHelper(s1[:i], s2[:i]) and isScrambleHelper(s1[i:], s2[i:])) or (isScrambleHelper(s1[:i], s2[-i:]) and isScrambleHelper(s1[i:], s2[:-i])):
                    dp[(s1, s2)] = True
                    return True
            dp[(s1, s2)] = False
            return False
        
        return isScrambleHelper(s1, s2)