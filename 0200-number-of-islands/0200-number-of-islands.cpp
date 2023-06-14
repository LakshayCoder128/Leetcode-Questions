class Solution {
public:
    void solve(vector<vector<char>>& grid,int &ans){
    
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    ans++;
                    eraseIslands(grid,i,j);
                }
            }
        }
        
    }
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        solve(grid,ans);
        return ans;
    }
};