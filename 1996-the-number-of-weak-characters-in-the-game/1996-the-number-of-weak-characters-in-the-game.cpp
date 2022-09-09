class Solution
{
    public:
        static bool comp(vector<int> &a, vector<int> &b)
        {
            if (a[0] == b[0])
            {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        }
    int numberOfWeakCharacters(vector<vector < int>> &properties)
    {

       	//         Brute Force : TLE O(n2) + O(1);
        /*   int weakChar = 0;
        int n = properties.size();
        for(int i=0;i < n;i++){
            int attack = properties[i][0];
            int defense = properties[i][1];
            for(int j=0;j < n;j++){
                if(attack < properties[j][0] && defense < properties[j][1]){
                    weakChar++;
                    break;
                }
            }
        }
        return weakChar;

*/
        int weakChar = 0;
        int n = properties.size();
        int mini = INT_MIN;
        sort(properties.begin(), properties.end(), comp);

        for (int i = properties.size() - 1; i >= 0; i--)
        {

            if (properties[i][1] < mini)
            {
                weakChar++;
            }
            mini = max(mini, properties[i][1]);
        }

        return weakChar;
    }
};