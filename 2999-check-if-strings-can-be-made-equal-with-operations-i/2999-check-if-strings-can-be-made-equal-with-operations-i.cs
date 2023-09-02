public class Solution {
    public bool CanBeEqual(string s1, string s2) {
        for (int i = 0; i < 2; i++) {
            if (s1[i] == s2[i] || s1[i] == s2[i + 2]) {
                if (s1[i] == s2[i]) continue;
                else {
                    char[] s2Chars = s2.ToCharArray();
                    char temp = s2Chars[i];
                    s2Chars[i] = s2Chars[i + 2];
                    s2Chars[i + 2] = temp;
                    s2 = new string(s2Chars);
                }
            } else {
                return false;
            }
        }

        if (s1[3] == s2[3] && s1[2] == s2[2])
            return true;
        return false;
    }
}