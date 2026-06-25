class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1) return n;
        vector<int> candy(ratings.size(),1);
        for (int i = 1; i< n;i++){
            if(ratings[i]>ratings[i-1]){
               candy[i] = candy[i - 1] + 1;
            }
        }
        int total = candy[n-1];
        for(int i = n-2; i>=0;i--){
            if(ratings[i+1]<ratings[i]){
                candy[i] = max(candy[i],candy[i+1]+1);
            }
            total += candy[i];
        }
        
        return total;
    }
};