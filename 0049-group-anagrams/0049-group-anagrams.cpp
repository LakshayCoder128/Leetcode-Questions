class Solution {
public:
    
    // O(m*nlogn + m*n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map 
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            // string ko sort kiya 
            sort(t.begin(), t.end());
            // sorted string ko key treat krke original string ko uske sath map kiya
            mp[t].push_back(s);
        }
        // final result
        vector<vector<string>> result;
        for (auto p : mp) { 
            result.push_back(p.second);
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> m;
//         for (int i = 0; i < strs.size(); i++) {
//             key generate ki
//             string key = getKey(strs[i]);
//             us key ko map kiya 
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
//         vector<int> count(26); // freuency store
//         for (int j = 0; j < str.size(); j++) {
//             count[str[j] - 'a']++;
//         }
        
//         string key = "";
//         for (int i = 0; i < 26; i++) {
//              key sorted order me generate ho gyi
//             key.append(to_string(count[i] + 'a'));
//         }
//         return key;
//     }
// };
