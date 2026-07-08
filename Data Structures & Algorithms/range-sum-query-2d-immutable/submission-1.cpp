class NumMatrix {
public:
    vector<vector<int>> prefix;
    int n; int m;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        prefix =  vector<vector<int>>(m,vector<int>(n,0));
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n; j++){
                prefix[i][j] = matrix[i][j];
                if(i-1>=0){
                    prefix[i][j] += prefix[i-1][j];
                }
                if(j-1>=0){
                    prefix[i][j] += prefix[i][j-1];
                    if(i-1>=0)
                    prefix[i][j] -= prefix[i-1][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefix[row2][col2] ;
        if(row1-1>=0){
            ans -= prefix[row1-1][col2];
        }
        if(col1-1>=0){
            ans -= prefix[row2][col1-1];
            if(row1-1>=0){
                ans += prefix[row1-1][col1-1];
            }
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */