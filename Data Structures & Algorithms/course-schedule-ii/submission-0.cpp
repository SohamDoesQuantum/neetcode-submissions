class Solution {
   public:
    vector<int> visited;
    vector<int> path_visited;
    vector<int> path;
    bool has_cycle(int v, vector<vector<int>>& adj) {
        visited[v] = 1;
        path_visited[v] = 1;
        for (int u : adj[v]) {
            if (!visited[u]) {
                if (has_cycle(u, adj)) return true;
            } else if (path_visited[u]) {
                return true;
            }
        }

        path_visited[v] = 0;
        path.push_back(v);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        visited = vector<int>(numCourses, 0);
        path_visited = vector<int>(numCourses, 0);
        
        for (auto& v : prerequisites) {
            int a = v[0];
            int b = v[1];
            adj[b].push_back(a);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (has_cycle(i, adj)) return {};
            }
        }
        reverse(path.begin(),path.end());
        return path;
    }
};
