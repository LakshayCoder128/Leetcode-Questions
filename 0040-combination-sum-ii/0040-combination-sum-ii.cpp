// Partially accepted 172/176

// class Solution {
// public:
//     void solve(vector<int>& candidates, int target,set<vector<int>>&ans,vector<int>&t,int ind){
//         if(target < 0) return;
//         if(target == 0){ans.insert(t);return;}

// for(int i=ind;i < candidates.size();i++){
//     t.push_back(candidates[i]);
//     solve(candidates,target-candidates[i],ans,t,i+1);
//     t.pop_back();
// }
//     }
//     vector<vector < int>> combinationSum2(vector<int>& candidates, int target) {
//         set<vector < int>>ans;
//         vector < int>t;
//         sort(candidates.begin(),candidates.end());
//         solve(candidates,target,ans,t,0);
//         vector<vector < int>>finans;
//         for(auto i:ans){
//             finans.push_back(i);
//         }

//         return finans;
//     }
// };
class Solution
{
    public:
        void solve(vector<int> &candidates, int target, vector<vector< int >> &ans, vector< int > &t, int ind)
        {
            if (target < 0) return;
            if (target == 0)
            {
                ans.push_back(t);
                return;
            }

            for (int i = ind; i < candidates.size(); i++)
            {

               	// special condition 
               	// is condition pr tabhi ayenge jb back track ho jaega kyunki usi ke baad (ind < i)  aur hume check kr rhe hai                	// candidates[i] == candidates[i-1]	// kyunko agr ye dono equal hai to is value ke liye hum phle hi traverse                  	// kr chuke hai aur ye sab possible ho paya sirf sorting ki wjh se  
               	// jab i taken index se aage ho aur  currindex ki value taken index ke barabar ho to mt lena 
                if (i > ind && candidates[i] == candidates[i - 1]) continue;

                t.push_back(candidates[i]);
                solve(candidates, target - candidates[i], ans, t, i + 1);
                t.pop_back();
            }
        }
    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> t;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, ans, t, 0);

        return ans;
    }
};