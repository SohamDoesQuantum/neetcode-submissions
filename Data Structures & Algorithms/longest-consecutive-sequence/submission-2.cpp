class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i : nums){
            st.insert(i);
        } 
        int ans = 0;
        for(int i : nums){
            int len =1 ;
            while(st.count(len+i)){
                len++;
            }
            ans = max(len,ans);
        }
        return ans;
    }
};
