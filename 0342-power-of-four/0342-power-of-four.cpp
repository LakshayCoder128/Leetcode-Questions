class Solution
{
    public:
        void solve(int n, long long &ans)
        {
            if (n <= ans) return;
            ans *= 4;
            solve(n, ans);
        }
    bool isPowerOfFour(int n)
    {
        if (n <= 0) return false;
        if (n == 1) return true;

       	// iterative 
       	// long long square = 1;
       	// for(int i=1;i < n;i++){
       	//     square *= 4;
       	//     if(square == n)return true;
       	//     if(square > n)break;
       	// }
       	// return false;

       	// recursive
       	// long long ans = 1;
       	// solve(n,ans);
       	// return n==ans;

       	// Mathematical using log and power function
        /*
                The Four Basic Properties of Logs
                logb(xy) = logbx + logby.
                logb(x/y) = logbx - logby.
                logb(xn) = n logbx.
            key--> logbx = logax / logab.
        */
        int root = log2(n) / log2(4);
        int square = pow(4, root);
        return square == n;
    }
};