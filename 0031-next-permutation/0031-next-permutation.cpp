class Solution
{
    public:
        void nextPermutation(vector<int> &p)
        {
            int n = p.size();

            int k, l;

            for (k = n - 2; k >= 0; k--)
            {
               	// increasing value kaha tak hai 
                if (p[k] < p[k + 1]) break;
            }

           	// agr increasing values end tak hai matlab ye maximum value hai 
           	// simply reverse krdo aur return 
            if (k < 0) return reverse(p.begin(), p.end());

           	// khi beech m hai breakpoint of increasing value 
           	// ab hum end se breakpoint tak search krenge ki koi value break point 
           	// vali value se bada to nhi 
           	// agr mile to index sambhal lo variable l mein

            for (l = n - 1; l > k; l--)
            {
                if (p[l] > p[k]) break;
            }

           	// mil gyi hume breakpoint se just bdi available value 
           	// swap krlo

            swap(p[k], p[l]);

           	// par abhi bhi ye next permutation nhi hai 
           	// hum reverse krna padega k+1 se end tak 
            reverse(p.begin() + k + 1, p.end());

           	// finally hum next permutation p phuch gye 

        }
};