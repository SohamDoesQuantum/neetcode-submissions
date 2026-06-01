class Solution {
public:
    int m;
    int n;
    void solve(vector<vector<char>>& board) {
        
        m = board.size(); n = board[0].size();
        vector<vector<bool>> avoid(m,vector<bool>(n,false));
          queue<pair<int,int>> q;
        for(int i =0; i<n;i++){
            if(board[0][i]=='O'&& !avoid[0][i]){
                avoid[0][i] = true;
                q.push({0,i});
            }
            if(board[m-1][i]=='O' && !avoid[m-1][i]){
                avoid[m-1][i] = true;
                q.push({m-1,i});
            }
        }
        for(int i = 0; i<m;i++){
            if(board[i][0]=='O'&& !avoid[i][0]){
                avoid[i][0]= true;
                q.push({i,0});
            }
            if(board[i][n-1]=='O' && !avoid[i][n-1]){
                avoid[i][n-1]=true;
                q.push({i,n-1});
            }
        }
      
        
        vector<int> di = {-1,1,0,0};
        vector<int> dj = {0,0,-1,1};
        while(!q.empty()){
            int p = q.size();
            while(p--){
                auto[i,j] = q.front();
                q.pop();
                for(int d = 0; d<4;d++){
                    int a = i+di[d], b = j+dj[d];
                    if(a>=0 && a<m && b>=0 && b<n && board[a][b]=='O' && !avoid[a][b]){
                        q.push({a,b});
                        avoid[a][b]=true;
                    }
                }

            }
        }
        
        for(int i =0; i<m;i++){
            for(int j = 0; j<n;j++){
                if(board[i][j]=='O' && !avoid[i][j]){
                    board[i][j]='X';
                }
            }
        }

    }
};
