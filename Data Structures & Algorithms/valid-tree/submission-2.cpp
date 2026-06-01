class Solution {
public:
    vector<int> visited;
    bool has_cycle(int node, int parent, vector<vector<int>>& adj){
        visited[node] = 1;
        for(int neigh : adj[node]){
            if(!visited[neigh]){
                if(has_cycle(neigh, node, adj)) return true;
            } 
            else {
                if(neigh != parent) return true;
            }
        }
        return false;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // Quick short-circuit: A tree MUST have exactly n - 1 edges
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for(auto& v : edges){
            int a = v[0];
            int b = v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        visited = vector<int>(n, 0);
        
        // Fire DFS exactly once from node 0.
        // If there's a cycle anywhere in this component, it's not a tree.
        if (has_cycle(0, -1, adj)) return false;
        
        // If any node was not reached by the single DFS, the graph is disconnected.
        for(int i : visited){
            if(i == 0) return false;
        }
        
        return true;
    }
};