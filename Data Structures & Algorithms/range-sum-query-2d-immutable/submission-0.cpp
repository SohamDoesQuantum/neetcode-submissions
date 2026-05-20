class NumMatrix {
   public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        dp.resize(m,vector<int>(n,0));
        for(int i  = 0; i< m;i++){
            for(int j = 0; j<n;j++){
                int up= (i>0)? dp[i-1][j]:0;
                int left = (j>0)? dp[i][j-1]:0;
                int diag = (i>0 && j>0)? dp[i-1][j-1]:0;
                dp[i][j] = left+up-diag+matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int up = (row1>0)? dp[row1-1][col2]:0;
        int left = (col1>0)? dp[row2][col1-1]:0;
        int diag = (row1>0 && col1>0)? dp[row1-1][col1-1]:0;
        return dp[row2][col2]-up-left+diag;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */