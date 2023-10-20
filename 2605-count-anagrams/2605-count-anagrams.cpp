int fact[100001] = {1, 1}, inv_fact[100001] = {1, 1}, mod = 1000000007;
class Solution {
public: 
int countAnagrams(string s) {
    if (fact[2] == 0) {
        vector<int> inv(100001, 1);
        for (long long i = 2; i < sizeof(fact) / sizeof(fact[0]); ++i) {
            fact[i] = i * fact[i - 1] % mod;
            inv[i] = mod - mod / i * inv[mod % i] % mod;
            inv_fact[i] = 1LL * inv_fact[i - 1] * inv[i] % mod;            
        }
    }
    int res = 1;
    for (int i = 0, j = 0; i <= s.size(); ++i)
        if (i == s.size() || s[i] == ' ') {
            long long cnt[26] = {}, prem = fact[i - j];
            for (int k = j; k < i; ++k)
                ++cnt[s[k] - 'a'];
            for (int rep : cnt)
                prem = prem * inv_fact[rep] % mod;
            res = res * prem % mod;
            j = i + 1;
        }
    return res;
}
};