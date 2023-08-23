class Solution
{
    public:
       	// 32 / 70 testcases passed
        string soln1(string s)
        {
            sort(s.begin(), s.end());
            int i = 1, j = s.length() - 1;
            while (i <= j)
            {
                if (s[i] == s[i - 1])
                {
                    swap(s[i], s[j]);
                    i++;
                    j--;
                }
                else i++;
            }
            bool check = 1;
            i = 1;
            while (i < s.length())
            {
                if (s[i] == s[i - 1])
                {
                    check = 0;
                    break;
                };
                i++;
            }

            if (check) return s;
            return "";
        }
    string soln2(string & s)
    {
       	// take frq
        int fq[26] = { 0 };
        for (int i = 0; i < s.length(); i++)
        {
            fq[s[i] - 'a']++;
            if (fq[s[i] - 'a'] > (s.length() + 1) / 2) return "";
        }
       	// max - heap
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++)
        {
            if (fq[i] > 0) pq.push({ fq[i],
                'a' + char(i) });
        }
        string ans = "";
        while (pq.size() >= 2)
        {
            pair<int, char> f = pq.top();
            pq.pop();
            pair<int, char> s = pq.top();
            pq.pop();
            ans += f.second;
            ans += s.second;
            if (f.first > 1) pq.push({ f.first - 1,
                f.second });
            if (s.first > 1) pq.push({ s.first - 1,
                s.second });
        }
        if (pq.size() == 1)
        {
            ans += pq.top().second;
        }
        return ans;
    }

    string reorganizeString(string s)
    {
        return soln2(s);
    }
};

/*
observations : 
frq 
1 ->c
0 -> b
1 -> a
c + b +c + b +a +b + a +c

*/