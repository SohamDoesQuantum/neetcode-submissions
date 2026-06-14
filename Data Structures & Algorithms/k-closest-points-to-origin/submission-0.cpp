class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using elem = pair<int,vector<int>>;
        priority_queue<elem,vector<elem>> pq;
        for(auto& v: points){
            int d = v[0]*v[0] + v[1]*v[1];
            pq.push({d,v});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
