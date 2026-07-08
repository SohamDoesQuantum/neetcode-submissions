class Solution {
public:
    string temp;
    string encode(vector<string>& strs) {
        for(string s:strs){
            temp+= to_string(s.size())+"#"+s;
        }
        return temp;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> ans;
        int curr_len = 0;
        while(i<s.size()){
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            i = j+1;
            j = i+len;
            ans.push_back(s.substr(i,len));
            i = j;
        }
        return ans;
    }
};
