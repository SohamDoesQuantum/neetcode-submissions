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
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        while (!q.empty() ) {
            int p = q.size();
            while (p--) {
                auto [i, j] = q.front();
                q.pop();
                for(int d = 0; d<4; d++){
                    int a = i+dx[d], b = j+dy[d];
                    if(a>=0 && a<m &&b>=0 && b<n &&!visited[a][b] && grid[a][b]==INF ){
                        grid[a][b]=dist;
                        q.push({a,b});
                    }
                }
            }
            dist++;
        }
    }
};
