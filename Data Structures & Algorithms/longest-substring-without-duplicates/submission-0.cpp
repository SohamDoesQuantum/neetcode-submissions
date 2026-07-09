class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0;
        int ans = 0;
        for(int right = 0; right<s.size(); right++){
            while(st.count(s[right])){
                st.erase(s[left++]);
            }
            st.insert(s[right]);
            int size = st.size();
            ans = max(ans,size);
        }
        return ans;
    }
};
