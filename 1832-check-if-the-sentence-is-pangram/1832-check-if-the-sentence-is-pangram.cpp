class Solution
{
    public:
        bool checkIfPangram(string sentence)
        {
            if (sentence.size() < 26)
            {
                return false;
            }
            int arr[26] = { 0 };
            for (int i = 0; i < sentence.length(); i++)
            {
                int word = sentence[i] - 'a';
                arr[word]++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (arr[i] == 0)
                {
                    return false;
                }
            }
            return true;
        }
};