class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i : nums){
            mp[i]++;
            if(mp[i]>n/2) return i;
        }
        return 0;
    }
};