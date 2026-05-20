class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int prefix =0 ;
        int cnt = 0 ;
        mp[0]++;
        for(int i = 0; i<n;i++){
            prefix += nums[i];
            if(mp.find(prefix-k)!=mp.end()){
                cnt += mp[prefix-k];
            }
            mp[prefix]++;
        }
        return cnt;

    }
};