// class Solution
// {
//     public:
//         string decToBinary(int n)
//         {
//            	// array to store binary number
//             string binaryNum;

//            	// counter for binary array
//             int i = 0;
//             while (n > 0)
//             {

//                	// storing remainder in binary array
//                 binaryNum[i] = n % 2;
//                 n = n / 2;
//                 i++;
//             }

//            	// printing binary array in reverse order
//             return binaryNum;
//         }
//     long long int binaryToDecimal(long long int n)
//     {
//         long long int num = n;
//         long long int dec_value = 0;

//        	// Initializing base value to 1, i.e 2^0
//         int base = 1;

//         int temp = num;
//         while (temp)
//         {
//             int last_digit = temp % 10;
//             temp = temp / 10;

//             dec_value += last_digit * base;

//             base = base * 2;
//         }

//         return dec_value;
//     }
//     int concatenatedBinary(int n)
//     {
//         const unsigned int M = 1000000007;
//         string binary = "";
//         for (int i = 1; i <= n; i++)
//         {
//             binary += decToBinary(i);
//         }

//         long long int a = stoi(binary);

//         long long ans = binaryToDecimal(a);

//         return ans % M;
//     }
// };
class Solution
{
    public:

        int numberOfBits(int n)
        {
            return log2(n) + 1;
        }

    int concatenatedBinary(int n)
    {
        long ans = 0, MOD = 1e9 + 7;

        for (int i = 1; i <= n; ++i)
        {
            int len = numberOfBits(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};