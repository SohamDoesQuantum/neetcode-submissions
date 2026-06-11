class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        queue<int> q;
        vector<vector<int>> adj(n);
        vector<int> del(n, 0);
        vector<int> visited(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0], u = edges[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        for (int i = 0; i < adj.size(); i++) {
            if (adj[i].size() == 1) {
                q.push(i);
                visited[i] = 1;
            }
        }

        while (n > 2) {
            int p = q.size();
            while (p--) {
                int node = q.front();
                q.pop();
                del[node] = 1;
                n--;
                for(int neigh: adj[node]){
                    if(!visited[neigh]){
                        int active_edges = 0;
                        for(int n_neigh: adj[neigh]){
                            if(!del[n_neigh]) active_edges++;
                        }
                        if(active_edges==1){
                            q.push(neigh);
                            visited[neigh]=1;
                        }
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < del.size(); i++) {
            if (del[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};