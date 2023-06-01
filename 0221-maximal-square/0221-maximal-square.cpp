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

       	// Recursion + memo
//         int Dpsolve(vector<vector < char>> &matrix, int i, int j, int &maximumSide, vector< vector< int>> &dp)
//         {
//             if (i >= matrix.size() || j >= matrix[0].size()) return 0;

//             if (dp[i][j] != -1) return dp[i][j];

//             int down = Dpsolve(matrix, i + 1, j, maximumSide, dp);
//             int right = Dpsolve(matrix, i, j + 1, maximumSide, dp);
//             int diagonal = Dpsolve(matrix, i + 1, j + 1, maximumSide, dp);

//             if (matrix[i][j] == '1')
//             {
//                 int side = (min(down, min(right, diagonal))) + 1;
//                 maximumSide = max(maximumSide, side);
//                 return dp[i][j] = side;
//             }
//             else return dp[i][j] = 0;
//         }

    int Tabsolve(vector<vector < char>> &matrix,int maximumSide)
    {
        
        vector<vector < int>> dp(matrix.size()+1, vector<int> (matrix[0].size()+1, 0));
        
        
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            for (int j = matrix[0].size() - 1; j >= 0; j--)
            {
                
                int down = dp[i + 1][j];
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];

                if (matrix[i][j] == '1')
                {
                    int side = (min(down, min(right, diagonal))) + 1;
                    maximumSide = max(maximumSide, side);
                    dp[i][j] = side;
                }
            
            }
        }
        return maximumSide;
    }
    int maximalSquare(vector<vector < char>> &matrix)
    {
        // vector<vector < int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1));
        int maximumSide = 0;
       	// Rsolve(matrix, 0, 0, maximumSide);
        //Dpsolve(matrix, 0, 0, maximumSide, dp);
        maximumSide = Tabsolve(matrix,maximumSide);

        return maximumSide * maximumSide;
    }
};