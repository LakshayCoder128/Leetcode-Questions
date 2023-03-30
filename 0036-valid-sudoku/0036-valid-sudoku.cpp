class Solution
{
    public:

        bool checkingSquare(int i, int j, vector<vector < char>> &board)
        {
            char check = board[i][j];
            return true;
        }

    bool isValidSudoku(vector<vector < char>> &board)
    {
       	// traverse the board
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
               	// check variable for the current element
                char check = board[i][j];
               	// if element is "." leave it
                if (check == '.') {}
                else
                {
                   	// check row
                    for (int k = 0; k < board[0].size() && k != j; k++)
                    {
                        if (check == board[i][k])
                        {
                            return false;
                        }
                    }
                   	// check col
                    for (int m = 0; m < board.size() && m != i; m++)
                    {
                        if (check == board[m][j]) return false;
                    }

                   	// check square 
                    int rowStart = (i / 3) *3;
                    int colStart = (j / 3) *3;
                    char target = board[i][j];

                    for (int row = rowStart; row < rowStart + 3; row++)
                    {
                        for (int col = colStart; col < colStart + 3; col++)
                        {
                            if (row == i && col == j)
                            {
                                continue;
                            }
                            if (board[row][col] == target)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};