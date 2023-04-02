class Solution
{
    public:
    int cnt=0;
        void solve(int &k, int &index, vector<int> &str)
        {
           	// base case
            // cout<<"case : "<<cnt++<<endl; 
            // cout<<"k : "<<k<< "Index : "<<index <<endl;
            if (str.size() == 1) return;
           	// index updation 
            int indi = (index + str.size() + k - 1) % str.size();
            // cout<<"Removed index value : "<<str[indi]<<endl;
            str.erase(str.begin() + indi);
            
            solve(k, indi, str);
        }
    int findTheWinner(int n, int k)
    {

        int index = 0;

        vector<int> str(n);
        for (int i = 1; i <= n; i++)
        {
            str[i-1]= i;
        }

        solve(k, index, str);
        int ans = str[0];
        return ans;
    }
};