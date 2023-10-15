class Solution {

    public String shortestBeautifulSubstring(String s, int k) {
        String ans = "";
        int len = 0;

        for (int i = 0; i < s.length(); i++) {
            int cnt = 0;
            for (int j = i; j < s.length(); j++) {
                if (s.charAt(j) == '1') {
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
                if (s.charAt(j) == '1') {
                    cnt++;
                    if (cnt == k) {
                        if (len == j - i + 1) {
                            if (ans.isEmpty()) {
                                ans = s.substring(i, i + len);
                            } else {
                                ans = ans.compareTo(s.substring(i, i + len)) < 0 ? ans : s.substring(i, i + len);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
}
