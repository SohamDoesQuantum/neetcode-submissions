class TimeMap {
   public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) { mp[key].push_back({value, timestamp}); }

    string get(string key, int timestamp) {
        int l = 0;
        vector<pair<string,int>> v =mp[key];
        int r = mp[key].size() - 1;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(v[mid].second<=timestamp){
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        if(ans!=-1)
            return v[ans].first;
        
        return "";
    }
};
