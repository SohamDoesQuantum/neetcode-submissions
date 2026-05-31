class Solution {
   public:
    vector<vector<char>> grid;
    vector<vector<int>> mark;
    int m;
    int n;
    void dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || mark[i][j]) return;
        if (grid[i][j] == '1') {
            mark[i][j] = 1;
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        mark = vector<vector<int>>(m, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && mark[i][j] == 0) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
