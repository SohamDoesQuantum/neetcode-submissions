class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path) {
        path[node] = 1;
        for (int neigh : adj[node]) {
            if (path[neigh])
                return true;
            else if (!visited[neigh]) {
                if (dfs(neigh, adj, visited, path)) return true;
            }
        }
        path[node] = 0;
        visited[node] = 1;
        return false;
    }
    bool detect_cycle(vector<vector<int>>& adj, int k) {
        vector<int> visited(k, 0);
        vector<int> path(k, 0);
        for (int i = 0; i < k; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, path)) return true;
            }
        }
        return false;
    }
    void assign_rank(int node, vector<int>& visited, vector<int>& ranks, int& rank,
                     vector<vector<int>>& adj) {
        visited[node] = 1;
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                assign_rank(neigh, visited, ranks, rank, adj);
            }
        }
        ranks[node] = rank--;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> row_adj(k);
        vector<vector<int>> col_adj(k);

        for (int i = 0; i < rowConditions.size(); i++) {
            int u = rowConditions[i][0], v = rowConditions[i][1];
            row_adj[u - 1].push_back(v - 1);
        }

        for (int i = 0; i < colConditions.size(); i++) {
            int u = colConditions[i][0], v = colConditions[i][1];
            col_adj[u - 1].push_back(v - 1);
        }

        if (detect_cycle(row_adj, k)) return {};
        if (detect_cycle(col_adj, k)) return {};
        vector<int> row_rank(k);
        vector<int> col_rank(k);
        int rank = k - 1;
        vector<int> visited(k, 0);
        for (int i = 0; i < k; i++) {
            if (!visited[i]) {
                assign_rank(i, visited, row_rank, rank, row_adj);
            }
        }

        visited.assign(k, 0);
        rank = k - 1;
        for (int i = 0; i < k; i++) {
            if (!visited[i]) {
                assign_rank(i, visited, col_rank, rank, col_adj);
            }
        }
        vector<vector<int>> matrix(k, vector<int>(k));
        for (int i = 0; i < k; i++) {
            if (row_rank[i] < k && col_rank[i] < k) {
                matrix[row_rank[i]][col_rank[i]] = i + 1;
            } else
                return {};
        }

        return matrix;
    }
};