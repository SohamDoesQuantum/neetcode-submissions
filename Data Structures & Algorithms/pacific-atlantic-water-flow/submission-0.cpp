class Solution {
   public:
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    int m, n;
    void ocean(bool is_pacific,vector<vector<int>>& heights ) {
        // pacific(is_pacific is true)
        queue<pair<int, int>> q;
        auto& visited = (is_pacific) ? pacific : atlantic;
        int r = (is_pacific) ? 0 : m - 1;
        for (int i = 0; i < n; i++) {
            if (!visited[r][i]) {
                visited[r][i] = true;
                q.push({r, i});
            }
        }
        int c = (is_pacific) ? 0 : n - 1;
        for (int i = 0; i < m; i++) {
            if (!visited[i][c]) {
                visited[i][c] = true;
                q.push({i, c});
            }
        }
        vector<int> di = {-1, 1, 0, 0};
        vector<int> dj = {0, 0, -1, 1};
        while (!q.empty()) {
            int p = q.size();
            while (p--) {
                auto [i, j] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int a = i + di[d], b = j + dj[d];
                    if (a >= 0 && a < m && b >= 0 && b < n && heights[a][b] >= heights[i][j] &&
                        !visited[a][b]) {
                        q.push({a, b});
                        visited[a][b] = true;
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        m = heights.size();
        n = heights[0].size();

        pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        atlantic = vector<vector<bool>>(m, vector<bool>(n, false));

        ocean(true,heights); ocean(false,heights);
        vector<vector<int>> ans;
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};
