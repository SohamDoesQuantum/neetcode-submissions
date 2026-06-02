class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> reached(n,INT_MAX);
        reached[k-1] = 0;
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto& v : times){
            mp[v[0]-1].push_back({v[1]-1,v[2]});
        }
        int time =0 ;
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0,k-1}); //time,node
        while(!pq.empty()){
            int node = pq.top()[1];
            int curr_time = pq.top()[0];
            pq.pop();
            
            if(curr_time>reached[node]) continue;
            time = max(time,curr_time);
            for(auto& v : mp[node]){
                int child = v.first, child_reach_time = v.second;
                int total_child_reach_time = curr_time+child_reach_time;
                if(reached[child]>total_child_reach_time){
                    pq.push({total_child_reach_time,child});
                    reached[child] = total_child_reach_time;
                }
            }
        }
        for(int i: reached){ if(i==INT_MAX) return -1;}
        return time;

    }
};
