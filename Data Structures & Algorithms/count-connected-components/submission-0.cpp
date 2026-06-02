class Solution {
public:
    
    void dfs(int node, vector<vector<int>>& adj,vector<int>& visited){
        visited[node] = 1;
        for(int u : adj[node]){
            if(!visited[u]){
                dfs(u,adj,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n);
        vector<vector<int>> adj(n);
        for(auto& e: edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adj,visited);
            }
        }

        return cnt;
    }
};
