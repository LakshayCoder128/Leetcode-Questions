class Solution
{
    public:
        bool checkIfPangram(string sentence)
        {
           	// if (sentence.size() < 26)
           	// {
           	//     return false;
           	// }
           	// int arr[26] = { 0 };
           	// for (int i = 0; i < sentence.length(); i++)
           	// {
           	//     int word = sentence[i] - 'a';
           	//     arr[word]++;
           	// }
           	// for (int i = 0; i < 26; i++)
           	// {
           	//     if (arr[i] == 0)
           	//     {
           	//         return false;
           	//     }
           	// }
           	// return true;

           	// seen variable
            int seen = 0;
            for (auto i: sentence)
            {
                int word = i - 'a';

               	// shifting left the bit by value = word    ex 25 incase of z
                int currBit = 1 << word;

                seen = seen | currBit;
            }
            return seen == (1 << 26) - 1;
        }
};