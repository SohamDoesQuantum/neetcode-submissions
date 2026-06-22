class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
       unordered_set<string> words(dictionary.begin(),dictionary.end()) ;
       vector<int> dp(s.size()+1,-1);
       dp[s.size()]= 0;
       search(0,s,words,dp);
       return dp[0];
    }
    int search(int i, const string& s, unordered_set<string>&words,vector<int>& dp){
        if(dp[i]!=-1) return dp[i];
        int res = 1 + search(i+1,s,words,dp);
        for(int j = i; j<s.size(); j++){
            if(words.count(s.substr(i,j-i+1))){
                res = min(res,search(j+1,s,words,dp));
            }
        }
        dp[i] = res;
        return res;
    }
};