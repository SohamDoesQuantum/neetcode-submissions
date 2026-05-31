class Solution {
   public:
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }
        int dist = 1;
        while (!q.empty()) {
            int p = q.size();
            while (p--) {
                auto [i, j] = q.front();
                q.pop();
                if (i - 1 >= 0 && grid[i - 1][j] == INF && !visited[i-1][j]) {
                    grid[i - 1][j] = dist;
                    q.push({i - 1, j});
                    visited[i-1][j] = true;
                }
                if (i + 1 < m && grid[i + 1][j] == INF && !visited[i+1][j]) {
                    grid[i + 1][j] = dist;
                    q.push({i + 1, j});
                    visited[i+1][j] = true;
                }
                if (j + 1 < n && grid[i][j + 1] == INF && !visited[i][j+1]) {
                    grid[i][j + 1] = dist;
                    q.push({i,j+1});
                    visited[i][j+1] = true;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == INF && !visited[i][j-1]) {
                    grid[i][j - 1] = dist;
                    q.push({i,j-1});
                    visited[i][j-1] = true;
                }
            }
            dist++;
        }
    }
};
