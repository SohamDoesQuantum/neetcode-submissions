class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string &s : strs){
            vector<int> k (26,0);
            for(char c : s){
                k[c-'a']++;
            }
            string key = "";
            for(int x : k){
                key += to_string(x)+"#";
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> arr;
        for(auto &it : mp){
            arr.push_back(it.second);
        }
        return arr;
    }
};
