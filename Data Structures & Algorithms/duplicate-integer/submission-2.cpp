class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
            if(mp[i]>1) return true;
        }
        return false;
    }
};