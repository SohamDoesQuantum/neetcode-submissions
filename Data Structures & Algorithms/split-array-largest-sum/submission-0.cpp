class Solution {
   public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        int res = 0;
        while(l<=r){
            int mid =  (l+r)/2;
            if(can_split(mid,nums,k)){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
    private:
    bool can_split(int mid,vector<int>&nums,int k){
        int cnt = 1,curr_sum = 0;
        for(int i = 0; i< nums.size();i++){
            curr_sum += nums[i];
            if(curr_sum>mid){
                cnt++;
                if(cnt>k) return false;
                curr_sum = nums[i];
            }
        }
        return true;
    }
};