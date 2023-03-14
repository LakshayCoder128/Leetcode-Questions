class Solution
{
    public:
        void sortColors(vector<int> &n)
        {
            if (n.size() == 1) return;
            if (n.size() == 2)
            {
                if (n[0] > n[1]) swap(n[0], n[1]);
                return;
            }
            int s = 0, e = n.size() - 1, m = 0;

            while (m <= e)
            {
                if (n[m] == 0) swap(n[m++], n[s++]);
                else if (n[m] == 2) swap(n[m], n[e--]);
                else if (n[m] == 1) m++;
             
            }
        }
};