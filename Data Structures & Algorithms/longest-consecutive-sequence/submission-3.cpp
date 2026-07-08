class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int max_len = 0;
        for(int i : nums){
            int len = 1;
            while(st.count(i-1)){
                len++;
                i--;
            }
            max_len = max(max_len,len);
        }
        return max_len;
    }
};