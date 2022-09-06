class Solution
{
    public:
        int p = 1e9 + 7;
    int numberOfWays(int a, int b, int k)
    {
        if ((a - b - k) % 2) return 0;
        if (abs(a - b) > k) return 0;
        long long res = 1 ;
        for (int i = 0; i < (b - a + k) / 2; ++i)
        {
            res = res *(k - i) % p;
            res = res* inv(i + 1) % p;
        }
        return res;
    }

    long inv(long a)
    {
        if (a == 1) return 1;
        return (p - p / a) *inv(p % a) % p;
    }
};