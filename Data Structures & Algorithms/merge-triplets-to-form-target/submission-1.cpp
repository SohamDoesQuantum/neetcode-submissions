class Solution {
public:
    bool valid(vector<int>& a, vector<int>&b){
        
        if(a[0]>b[0] || a[1]>b[1] || a[2]>b[2])
            return false;
        if(a[0]<b[0] && a[1]<b[1] && a[2]<b[2])
            return false;
        return true;    
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<vector<int>> consider;
        for(int i = 0; i< n; i++){
            if(valid(triplets[i],target))
                consider.push_back(triplets[i]);
        }
        for (int i = 0; i< 3; i++){
            bool f = false;
            for(auto& v: consider){
                if(v[i]==target[i]){
                    f = true;
                    break;
                }
            }
            if(f == false) return false;
        }
        return true;

    }
};
