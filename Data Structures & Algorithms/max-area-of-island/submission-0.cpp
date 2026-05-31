class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> mark;
    int m; int n;
    int dfs(int i, int j){
        if(i<0 || j<0 || i>=m || j>=n|| mark[i][j] || grid[i][j]==0)
            return 0;
        {mark[i][j] = 1;
        return 1 + dfs(i-1,j)+dfs(i+1,j)+dfs(i,j-1)+dfs(i,j+1);}
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size(); n = grid[0].size();
        mark = vector<vector<int>>(m,vector<int>(n,0));
        int area = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] && !mark[i][j]){
                    area  = max(area, dfs(i,j));
                }
            }
        }

        return area;
    }
};
