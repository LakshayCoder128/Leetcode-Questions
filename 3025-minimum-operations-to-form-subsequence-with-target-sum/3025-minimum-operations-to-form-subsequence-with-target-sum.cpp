class Solution
{
    public:
    // TLE
        int sol1(vector<int> &a, int target)
        {
            int sum = 0;
            priority_queue<int> pq;
            for (auto i: a)
            {
                pq.push(i);
                sum += i;
            }
            int ans = 0;
            while (!pq.empty() && sum > target)
            {
                int num = pq.top();
                pq.pop();
                num = (num >> 1);
                sum -= num;
                pq.push(num);
                ans++;
            }
            if (sum == target) return ans;
            else return -1;
        }

    // Accepted
    int sol2(vector<int> &nums, int target)
    {
        int cnt[32] = {}, ops = 0, j = 32;
        for (int n: nums)
            ++cnt[(int) log2(n)];
        for (int i = 0; i < 31; ++i)
        {
            int bit = 1 << i;
            if (target & bit)
            {
                if (cnt[i])
                    --cnt[i];
                else
                    j = min(j, i);
            }
            if (cnt[i] && j < i)
            {
                --cnt[i];
                ops += i - j;
                j = 32;
            }
            cnt[i + 1] += cnt[i] / 2;
        }
        return j < 32 ? -1 : ops;
    }
    int minOperations(vector<int> &a, int target)
    {

        return sol2(a, target);
    }
};