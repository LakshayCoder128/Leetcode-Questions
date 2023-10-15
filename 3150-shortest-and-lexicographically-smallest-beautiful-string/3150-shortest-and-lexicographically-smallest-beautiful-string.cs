public class Solution {
    public string ShortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int len = 0;

        for (int i = 0; i < s.Length; i++) {
            int cnt = 0;
            for (int j = i; j < s.Length; j++) {
                if (s[j] == '1') {
                    cnt++;
                    if (cnt == k) {
                        if (len == 0) {
                            len = j - i + 1;
                        } else if (len > j - i + 1) {
                            len = j - i + 1;
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < s.Length; i++) {
            int cnt = 0;
            for (int j = i; j < s.Length; j++) {
                if (s[j] == '1') {
                    cnt++;
                    if (cnt == k) {
                        if (len == j - i + 1) {
                            if (string.IsNullOrEmpty(ans)) {
                                ans = s.Substring(i, len);
                            } else {
                                ans = ans.CompareTo(s.Substring(i, len)) < 0 ? ans : s.Substring(i, len);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
}