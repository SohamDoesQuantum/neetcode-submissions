class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> mark (m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i = 0; i<m;i++){
            for(int j =0; j<n;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int p = q.size();
            bool rotted = false;
            while(p--){
                auto [i,j] = q.front();
                q.pop();
                vector<int> di = {-1,1,0,0};
                vector<int> dj = {0,0,-1,1};
                for(int d =0; d<4;d++){
                    int a = i+di[d], b = j+dj[d];
                    if(a>=0 && a<m && b>=0 && b<n && grid[a][b]==1 && !mark[a][b]){
                        q.push({a,b});
                        mark[a][b] = true;
                        grid[a][b]=2;
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if(rotted)time++;
        }
        if(fresh) return -1;
        return time;
    }
};
