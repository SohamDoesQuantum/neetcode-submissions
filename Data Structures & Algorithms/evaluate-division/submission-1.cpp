class Solution {
   public:
    unordered_map<string, vector<pair<string, double>>> adj;

    double dfs(string& current, string& target, unordered_map<string, int>& visited) {
        if (current == target) return 1.0;
        
        visited[current] = 1;
        
        for (auto& neighbor : adj[current]) {
            string nextNode = neighbor.first;
            double weight = neighbor.second;
            
            if (!visited[nextNode]) {
                
                double res = dfs(nextNode, target, visited);
                
                
                if (res != -1.0) {
                    return weight * res;
                }
            }
        }
        

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string Ai = equations[i][0], Bi = equations[i][1];
            double val = values[i];
            adj[Ai].push_back({Bi, val});
            adj[Bi].push_back({Ai, 1 / val});
        }
        vector<double> ans;
        for (auto& q : queries) {
            string c = q[0], d = q[1];
            
            // If either node doesn't exist in our graph equations
            if (adj.find(c) == adj.end() || adj.find(d) == adj.end()) {
                ans.push_back(-1.0);
                continue;
            }
            
            unordered_map<string, int> visited;
            
            double result = dfs(c, d, visited);
            ans.push_back(result);
        }
        return ans;
    }
};