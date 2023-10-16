using System.Collections.Generic;

public class Solution {
    private Dictionary<string, bool> dp = new Dictionary<string, bool>();

    public bool IsScramble(string s1, string s2) {
        if (s1.Length != s2.Length)
            return false;
        if (s1 == s2)
            return true;
        if (dp.ContainsKey(s1 + s2))
            return dp[s1 + s2];

        bool res = false;
        int[] v = new int[26];
        for (int i = 0; i < s1.Length; i++) {
            v[s1[i] - 'a']++;
            v[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (v[i] != 0) {
                dp[s1 + s2] = false;
                return false;
            }
        }
        for (int i = 1; i < s1.Length; i++) {
            res = res || (IsScramble(s1.Substring(0, i), s2.Substring(0, i)) && IsScramble(s1.Substring(i), s2.Substring(i)));
            res = res || (IsScramble(s1.Substring(0, i), s2.Substring(s1.Length - i)) && IsScramble(s1.Substring(i), s2.Substring(0, s1.Length - i)));
        }
        dp[s1 + s2] = res;
        return res;
    }
}