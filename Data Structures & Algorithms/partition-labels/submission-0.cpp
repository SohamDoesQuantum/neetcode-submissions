class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i<s.size(); i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = {i,i};
            }
            else{
                mp[s[i]][1] = i;
            }
        }
        vector<vector<int>> intervals;
        for (auto& it : mp){
            intervals.push_back(it.second);
        }
        sort(intervals.begin(),intervals.end());
        vector<int> res;
        int curr_start = intervals[0][0];
        int curr_end = intervals[0][1];
        for (int i = 1; i<intervals.size();i++){
            int start_i = intervals[i][0];
            int end_i = intervals[i][1];

            if(start_i<curr_end && end_i>curr_end){
                curr_end = end_i;
            }
            else if(start_i>curr_end){
                res.push_back(curr_end-curr_start+1);
                curr_start = start_i;
                curr_end = end_i;
            }
        }
        res.push_back(curr_end-curr_start+1);
        return res;
    }
};
