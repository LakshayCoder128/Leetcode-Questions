class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> m;
//         for (int i = 0; i < strs.size(); i++) {
//             string key = getKey(strs[i]);
//             m[key].push_back(strs[i]);
//         }
        
//         vector<vector<string>> result;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             result.push_back(it->second);
//         }
//         return result;
//     }
// private:
//     string getKey(string str) {
//         vector<int> count(26);
//         for (int j = 0; j < str.size(); j++) {
//             count[str[j] - 'a']++;
//         }
        
//         string key = "";
//         for (int i = 0; i < 26; i++) {
//             key.append(to_string(count[i] + 'a'));
//         }
//         return key;
//     }
// };
