class Solution {
    public boolean canBeEqual(String s1, String s2) {
        for (int i = 0; i < 2; i++) {
            if (s1.charAt(i) == s2.charAt(i) || s1.charAt(i) == s2.charAt(i + 2)) {
                if (s1.charAt(i) == s2.charAt(i)) continue;
                else {
                    char[] s2Chars = s2.toCharArray();
                    char temp = s2Chars[i];
                    s2Chars[i] = s2Chars[i + 2];
                    s2Chars[i + 2] = temp;
                    s2 = new String(s2Chars);
                }
            } else {
                return false;
            }
        }

        if (s1.charAt(3) == s2.charAt(3) && s1.charAt(2) == s2.charAt(2))
            return true;
        return false;
    }
}