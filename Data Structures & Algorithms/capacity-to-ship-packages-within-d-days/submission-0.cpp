class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        int weight = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(can_load(mid,weights,days)){
                weight = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return weight;
    }
private:
    bool can_load(int w,vector<int>& weights, int days){
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i< weights.size(); i++){
            sum += weights[i];
            if(sum>w){
                cnt++;
                if(cnt>days){
                    return false;
                }
                sum = weights[i];
            }
        }
        return true;
    }
};