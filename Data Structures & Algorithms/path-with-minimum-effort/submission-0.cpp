class Solution {
public:
    vector<vector<int>> effort;
    int m; int n;
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(); n = heights[0].size();
        effort = vector<vector<int>> (m,vector<int>(n,INT_MAX));

        effort[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            int curr_eff = pq.top()[0];
            int row = pq.top()[1], col = pq.top()[2];
            if (row == m - 1 && col == n - 1) return curr_eff;
            pq.pop();
            for(int d = 0; d<4; d++){
                int a = row+dx[d], b = col+dy[d];
                if(a>=0 && a<m && b>=0 &&b<n){
                    int single_jump = abs(heights[row][col]-heights[a][b]);
                    int total_path_effort = max(curr_eff,single_jump);
                    if(total_path_effort<effort[a][b]){
                        effort[a][b] = total_path_effort;
                        pq.push({total_path_effort,a,b});
                    }
                } 
            }
        }
        return effort[m-1][n-1];
        
    }
};