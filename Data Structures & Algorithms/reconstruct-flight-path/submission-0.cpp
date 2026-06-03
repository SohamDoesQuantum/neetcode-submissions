class Solution {
public:
    int n;
    unordered_map<string,vector<pair<string,int>>> adj;
    vector<int> visited;
    bool dfs(string src, vector<string>& res){
        if(res.size()==n+1) return true;
        if(adj.find(src)==adj.end()) return false;
        for(auto& it: adj[src]){
            string dst = it.first;
            int ticket_ = it.second;
            if(visited[ticket_]==0){
                visited[ticket_]=1;
                res.push_back(dst);

                if(dfs(dst,res)==true){
                    return true;
                }
                visited[ticket_]=0;
                res.pop_back();
            }
        }

        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
        n = tickets.size();
        for(int i =0; i<n; i++){
            string from_i = tickets[i][0], to_i = tickets[i][1];
            adj[from_i].push_back({to_i,i});
        }
        visited.assign(n,0);
        vector<string> res;
        res.push_back("JFK");
        dfs("JFK",res);
        return res;
        
    }
};
