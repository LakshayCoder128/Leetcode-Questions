class Solution
{
    public:
//         int solve(vector<vector < char>> &matrix, int i, int j, int &maximumSide)
//         {
//             if (i >= matrix.size() || j >= matrix[0].size()) return 0;

//             int down = solve(matrix, i + 1, j, maximumSide);
//             int right = solve(matrix, i, j + 1, maximumSide);
//             int diagonal = solve(matrix, i + 1, j + 1, maximumSide);

//             if (matrix[i][j] == '1')
//             {
//                 int side = (min(down, min(right, diagonal))) + 1;
//                 maximumSide = max(maximumSide, side);
//                 return side;
//             }
//             else return 0;
//         }

    int Dpsolve(vector<vector < char>> &matrix, int i, int j, int &maximumSide, vector< vector< int>> &dp)
    {
        if (i >= matrix.size() || j >= matrix[0].size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        
        int down = Dpsolve(matrix, i + 1, j, maximumSide,dp);
        int right = Dpsolve(matrix, i, j + 1, maximumSide,dp);
        int diagonal = Dpsolve(matrix, i + 1, j + 1, maximumSide,dp);

        if (matrix[i][j] == '1')
        {
            int side = (min(down, min(right, diagonal))) + 1;
            maximumSide = max(maximumSide, side);
            return dp[i][j] = side;
        }
        else return dp[i][j] = 0;
    }
    int maximalSquare(vector<vector < char>> &matrix)
    {
        vector<vector < int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1));
        int maximumSide = 0;
       	// Rsolve(matrix, 0, 0, maximumSide);
        Dpsolve(matrix, 0, 0, maximumSide, dp);

        return maximumSide * maximumSide;
    }
};