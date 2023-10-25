class Solution
{
    public:
       	
        int kthGrammar(int n, int k)
        {
            if (n == 1 || k == 1) return 0;
            int mid = pow(2, n - 2);	// mid element :  length of nth row  =  2^n-1   so mid = 2^n-2

           	// if k is less than mid then we can simply check k for n-1 row as the string before mid in nth row is the copy of the n-1 th row 
            if (k <= mid) return kthGrammar(n - 1, k);
           	// otherwise we obsereved that the string after the mid is complement of the n-1 th string 
            else return !kthGrammar(n - 1, k - mid);
        }
};