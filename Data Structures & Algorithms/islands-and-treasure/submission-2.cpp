class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int dist = 0;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int a = i + dx[d], b = j + dy[d];
                if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == INT_MAX) {
                    grid[a][b] =grid[i][j]+1;
                    q.push({a, b});
                }
            }
            dist++;
        }
    }
};
