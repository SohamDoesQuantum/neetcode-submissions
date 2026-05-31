class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);
        for(int i = 0; i<trust.size();i++){
            int u = trust[i][0];
            int v = trust[i][1];
            adj[v].push_back(u);
        }
        bool judge_found = false;
        int judge = -1;
        for(int i = 1;i<=n;i++){
            if(adj[i].size()==n-1){
                if(!judge_found){
                    judge_found = true;
                    judge = i;
                }
                else{
                    return -1;
                }
            }
        }
        for(int i = 0; i<trust.size();i++){
            if(trust[i][0]==judge){
                return -1;
            }
        }
        return judge;
    }
};