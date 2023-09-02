class Solution {
    // Helper function to calculate factorial modulo moduloValue
    private int f(int totalElements, int selectedElements, int moduloValue) {
        if (selectedElements == 0)
            return 1;

        int[] temp = new int[totalElements + 1];
        temp[0] = 1;

        // Calculate factorial modulo moduloValue for each number up to totalElements
        for (int i = 1; i <= totalElements; i++)
            temp[i] = (int) (1L * temp[i - 1] * i % moduloValue);

        int result = temp[totalElements];
        result = (int) (1L * result * help(temp[selectedElements], moduloValue) % moduloValue);
        result = (int) (1L * result * help(temp[totalElements - selectedElements], moduloValue) % moduloValue);

        return result;
    }

    // Helper function to calculate modular inverse using extended Euclidean algorithm
    private int help(int num, int moduloValue) {
        int mod0 = moduloValue;
        int y = 0, x = 1;

        while (num > 1) {
            int quotient = num / moduloValue;
            int temp = moduloValue;
            moduloValue = num % moduloValue;
            num = temp;
            temp = y;
            y = x - quotient * y;
            x = temp;
        }

        if (x < 0)
            x += mod0;

        return x;
    }

    public int countKSubsequencesWithMaxBeauty(String inputStr, int kValue) {
        int moduloValue = 1_000_000_007;
        HashMap<Character, Integer> mp = new HashMap<>();

        for (char ch : inputStr.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }

        if (mp.size() < kValue) {
            return 0;
        }

        List<Integer> charCounts = new ArrayList<>(mp.values());
        charCounts.sort(Collections.reverseOrder());

        int answer = 1;
        int tt = charCounts.size();
        int lowestCharCount = charCounts.get(kValue - 1);
        int tll = 0, currentLowestCharCount = 0;

        for (int i = 0; i < tt; i++) {
            if (i < kValue) {
                answer = (int) (1L * answer * charCounts.get(i) % moduloValue);
                if (charCounts.get(i) == lowestCharCount) {
                    currentLowestCharCount++;
                }
            }

            if (charCounts.get(i) == lowestCharCount) {
                tll++;
            }
        }

        answer = (int) (1L * answer * f(tll, currentLowestCharCount, moduloValue) % moduloValue);
        return answer;
    }
}