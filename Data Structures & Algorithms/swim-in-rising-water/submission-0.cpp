class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>time(n, vector<int>(n,INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({grid[0][0], 0, 0});  // time,i,j
        time[0][0] = grid[0][0];
        vector<int> di = {-1,1,0,0}, dj = {0,0,-1,1};
        while (pq.size()) {
            vector<int> curr = pq.top();
            pq.pop();
            int i = curr[1], j = curr[2], curr_time = curr[0];
            if(i==n-1 && j==n-1) return curr_time;
            for(int d = 0; d<4;d++){
                int a = i+di[d], b = j+dj[d];
                if(a>=0 && a<n && b>=0 && b<n){
                    int potential_time = max(curr_time, grid[a][b]);
                    if(potential_time<time[a][b]){
                        time[a][b]=potential_time;
                        pq.push({time[a][b],a,b});
                    }
                }
            }
        }
        return 0;
    }
};
