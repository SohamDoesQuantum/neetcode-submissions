class Solution {
   public:
    vector<vector<int>> adj;
    vector<int> nodes;
    bool is_invalid = false;
    void dfs(int curr_node, string& topo) {
        if(is_invalid) return;
        nodes[curr_node] = 0;
        for (int neigh : adj[curr_node]) {
            if(nodes[neigh]==0){
                is_invalid= true;
                return;
            }
            if (nodes[neigh] == 1) {
                dfs(neigh, topo);
            }
        }
        nodes[curr_node]=2;
        char ch = static_cast<char>(curr_node + 'a');
        topo.push_back(ch);
    }
    void compare(string& a, string b) {
        int len = min(a.size(),b.size());
        if(a.size()>b.size() && a.substr(0,len)==b) {
            is_invalid = true;
            return;
        }
        for (int i = 0; i <len; i++) {
            char c = a[i], d = b[i];
            if (c != d) {
                adj[c - 'a'].push_back(d - 'a');
                break;
            }
        }
    }
    string foreignDictionary(vector<string>& words) {
        nodes = vector<int>(26, -1);
        adj.assign(26,vector<int>());
        int n = words.size();
        for(string& w: words){
            for(char c : w){
                nodes[c-'a']=1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            compare(words[i], words[i + 1]);
            if(is_invalid) return "";
        }

        string topo;
        for (int i = 0; i < 26; i++) {
            if (nodes[i] == 1) {
                dfs(i, topo);
                if(is_invalid) return "";
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }
};
