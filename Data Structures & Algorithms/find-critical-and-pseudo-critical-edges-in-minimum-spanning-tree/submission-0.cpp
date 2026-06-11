class Solution {
   public:
    int standard_wt;
    int find_parent(int a, vector<int>& parent) {
        if (a == parent[a]) {
            return a;
        } else
            return parent[a] = find_parent(parent[a], parent);
    }
    bool unite(int a, int b, vector<int>& parent) {
        int pa = find_parent(a, parent);
        int pb = find_parent(b, parent);
        if (pa != pb) {
            parent[pb] = pa;
            return true;
        }
        return false;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });
        vector<int> critical, pseudo;

        standard_wt = check_critical(n, edges, -1);
        for (int i = 0; i < edges.size(); i++) {
            if (check_critical(n, edges, edges[i][3])>standard_wt) {
                critical.push_back(edges[i][3]);
            }
            
            else if (check_pseudo_critical(n, edges, edges[i][3])== standard_wt) {
                pseudo.push_back(edges[i][3]);
            }
        }

        return{critical,pseudo};
    }
    int check_critical(int n, vector<vector<int>>& edges, int banned_edge) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int MST_wt = 0;
        int edge_count = 0;
        for (int e = 0; e < edges.size(); e++) {
            if (edges[e][3] == banned_edge) continue;
            int from = edges[e][0];
            int to = edges[e][1];
            int wt = edges[e][2];
            if (unite(from, to, parent)) {
                MST_wt += wt;
                edge_count++;
            }
        }
        if (edge_count != n - 1) return INT_MAX;
        return MST_wt;
    }
    int check_pseudo_critical(int n, vector<vector<int>>& edges, int forced_edge) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int edge_count = 0;
        int MST_wt = 0;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][3] == forced_edge) {
                int from = edges[i][0];
                int to = edges[i][1];
                int wt = edges[i][2];
                unite(from, to, parent);
                MST_wt += wt;
                edge_count++;
                break;
            }
        }
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            int wt = edges[i][2];
            if (unite(from, to, parent)) {
                MST_wt += wt;
                edge_count++;
            }
        }
        return (edge_count==n-1)?MST_wt:INT_MAX;
    }
};