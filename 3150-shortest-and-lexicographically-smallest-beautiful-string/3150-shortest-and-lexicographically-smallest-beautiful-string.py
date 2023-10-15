class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        ans = ""
        max_len = 0

        for i in range(len(s)):
            cnt = 0
            for j in range(i, len(s)):
                if s[j] == '1':
                    cnt += 1
                    if cnt == k:
                        if max_len == 0:
                            max_len = j - i + 1
                        elif max_len > j - i + 1:
                            max_len = j - i + 1
                            break

        for i in range(len(s)):
            cnt = 0
            for j in range(i, len(s)):
                if s[j] == '1':
                    cnt += 1
                    if cnt == k:
                        if max_len == j - i + 1:
                            if not ans:
                                ans = s[i:i + max_len]
                            else:
                                ans = min(ans, s[i:i + max_len])

        return ans
