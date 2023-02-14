class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
           	//         O(N^2)
           	// vector<int> ans;
           	// for(int i=0;i < nums.size()-1;i++){
           	//     for(int j=i+1;j < nums.size();j++){
           	//         if(nums[i]+nums[j]==target){
           	//             ans.push_back(i);
           	//             ans.push_back(j);
           	//         }
           	//     }
           	// }
           	// return ans;

           	//   O(N)  Auxiliary space : O(N)

           	// vector<int> v;
           	// unordered_map<int, int> m;
           	// for (int i = 0; i < nums.size(); i++)
           	// {
           	//     if (m.find(target - nums[i]) != m.end())
           	//     {
           	//         v.push_back(m[target - nums[i]]);
           	//         v.push_back(i);
           	//         return v;
           	//     }
           	//     else
           	//         m[nums[i]] = i;
           	// }
           	// return v;
            /*
            Example 
            2,7,11,15      target =9

            9-2=7
            m.find(7)!=m.end()  	// false 
            m[2]=0

            m.find(9-7=2)!=m.end()  	// false
            m[7]=1;

            m.find(9-11=-2) 
            m[-2]

            */

            vector<int> ans;
            unordered_map<int, int> m;

            for (int i = 0; i < nums.size(); i++)
            {
                if (m.find(target - nums[i]) != m.end())
                {
                    ans.push_back(m[target - nums[i]]);
                    ans.push_back(i);
                    return ans;
                }
                m[nums[i]] = i;
            }
            return ans;
        }
};