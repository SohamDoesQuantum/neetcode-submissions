class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> adj(numCourses,vector<bool>(numCourses,false));
        for( int i = 0; i<numCourses; i++){
            adj[i][i] = false;
        }
        for(auto& it : prerequisites){
            adj[it[0]][it[1]] = true;
        }
        vector<bool> ans;
        build_reachability(prerequisites,adj, numCourses);
        for(auto& it: queries){
            ans.push_back(adj[it[0]][it[1]]);
        }
        return ans;
    }
    void build_reachability( vector<vector<int>>& prerequisites, vector<vector<bool>>& adj, int n){
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    adj[i][j] = adj[i][j] || adj[i][k]&&adj[k][j];
                }
            }
        }
    }
};