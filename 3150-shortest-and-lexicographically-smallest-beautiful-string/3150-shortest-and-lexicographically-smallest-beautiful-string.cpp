class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int cnt = 0;
            for (int j = i; j < s.length(); j++) {
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

        for (int i = 0; i < s.length(); i++) {
            int cnt = 0;
            for (int j = i; j < s.length(); j++) {
                if (s[j] == '1') {
                    cnt++;
                    if (cnt == k) {
                        if (len == j - i + 1) {
                            if (ans == "") {
                                ans = s.substr(i, len);
                            } else {
                                ans = min(ans, s.substr(i, len));
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};