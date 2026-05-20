class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = "";
        int mini = strs[0].size();
        for(int i = 0; i<strs.size();i++){
            if(mini>strs[i].size()){
                mini = strs[i].size();
            }
        }
        
        for(int i = 0; i<mini;i++){
            char c = strs[0][i];
            for(string s : strs){
                if(s[i]!=c) return pref;
            }
            pref += c;
        }

        return pref;
    }
};