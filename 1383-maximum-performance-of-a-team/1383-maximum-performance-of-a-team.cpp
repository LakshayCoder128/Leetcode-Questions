class Solution
{
    public:
        int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
        {
            vector<pair<int, int>> ess(n);
            for (int i = 0; i < n; ++i)
                ess[i] = { efficiency[i],
                    speed[i]
                };
            sort(rbegin(ess), rend(ess));
            long sumS = 0, res = 0;
            priority_queue<int, vector < int>, greater < int>> pq;	//min heap
            for (auto &[e, s]: ess)
            {
                //cout<<e<<" "<<s<<endl;
                pq.emplace(s);
                sumS += s;
                //cout<<"SumS :  <<sumS<<endl;
                if (pq.size() > k)
                {
                    sumS -= pq.top();
                    pq.pop();
                }
                //cout<<sumS<<endl;
                res = max(res, sumS *e);
                //cout<<"res : "<<res<<endl;
            }
            return res % (int)(1e9 + 7);
        }
};