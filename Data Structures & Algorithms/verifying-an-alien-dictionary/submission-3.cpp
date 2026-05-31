class Solution {
public:
    unordered_map<char, int> mp;
    bool isAlienSorted(vector<string>& words, string order) {
        int i = 0;
        for(char c : order){
            mp[c] = i++;
        }
        i = 0;
        int n = words.size();
        while(i+1<n){
            if(!compare(words[i],words[i+1])) return false;
            else i++;
        }
        return true;
    }
    bool compare(string& a, string& b){

        if(a.size()>b.size()) return !compare(b,a);
        int i = 0;
        while(i<a.size()){
            if(mp[a[i]]>mp[b[i]]) return false;
            else if(mp[a[i]]<mp[b[i]]) return true;
            i++;
        }
        return true;
    }
};