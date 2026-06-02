class Solution {
public:
    int find_parent(int a, vector<int>& parent){
        if(parent[a]==a) return a;
        return parent[a] = find_parent(parent[a],parent);
    }
    void unite(int a, int b, vector<int>& parent){
        int pa = find_parent(a, parent);
        int pb = find_parent(b, parent);

        if(pa!=pb){
            parent[pb] = pa;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        int ac = 0;
        int n = accounts.size();    vector<int> parent(n);
        for(int i = 0; i<n; i++) parent[i] = i;
        
        for(auto& v: accounts){
            for(int i = 1; i<v.size();i++){
                if(mp.find(v[i])!=mp.end()){
                    unite(mp[v[i]],ac,parent);
                }
                else{
                    mp[v[i]] = ac;
                }
            }
            ac++;
        }
        unordered_map<int,vector<string>> merge;
        for(int ac = 0; ac<n; ac++){
            int root = find_parent(ac,parent);

            for(int i = 1; i<accounts[ac].size();i++){
                merge[root].push_back(accounts[ac][i]);
            }
        }
        
        for(auto &it: merge){
            vector<string> emails = it.second;
            set<string> unique_emails(emails.begin(),emails.end());
            emails.assign(unique_emails.begin(),unique_emails.end());
            it.second = emails;
        }
        vector<vector<string>> ans;
        for(auto&it : merge){
            int ac = it.first;
            string name = accounts[ac][0];
            vector<string> v;
            v.push_back(name);
            
            for(string s : it.second){
                v.push_back(s);
            }
            ans.push_back(v);

        }

        return ans;

    }
};