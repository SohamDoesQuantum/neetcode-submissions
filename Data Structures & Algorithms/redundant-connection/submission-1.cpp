class Solution {
public:
    int find_parent(int a,vector<int>& parent){
        if(parent[a]==a) return a;
        return parent[a]=find_parent(parent[a],parent);
    }
    bool unite(int a, int b,vector<int>&parent){
        int pa = find_parent(a,parent);
        int pb = find_parent(b,parent);

        if(pa!=pb){
            parent[pa] = pb;
            return false;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = edges.size();
      vector<int> parent(n);
      for(int i = 0; i< n; i++){
        parent[i] = i;
      }
      for(auto& ed :edges){
        if(unite(ed[0]-1,ed[1]-1,parent)) return ed;
      }
      return {};
    }
};
