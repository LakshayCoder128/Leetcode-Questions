class Solution {
public:
 int mod = (int)1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int ans = 0;
        map<int, long long > m;
        
        for (int x : arr) {
            
            long long ways = 1;
            int max = (int)sqrt(x);
            for (int j = 0, left = arr[0]; left <= max; left = arr[++j]) {
                if (x % left != 0) continue;
                int right = x / left;
                if (m.find(right) != m.end())
                    ways = (ways + m[left] * m[right] * (left == right ? 1 : 2)) % mod;
            }
            
            m[x] = ways;
            ans = (int)((ans + ways) % mod);
        }
        return ans;
    }
    
};

