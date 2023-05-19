class Solution
{
    public:
        double pow(double x, int n)
        {
            if (n == 0) return 1;
            double val = pow(x, n / 2);
            if (n % 2 == 0)
                return val * val;
            else return x *val * val;
        }
    double myPow(double x, int n)
    {
        int power = abs(n);
        double ans = pow(x, power);

        if (n < 0) return 1 / ans;
        return ans;
    }
};