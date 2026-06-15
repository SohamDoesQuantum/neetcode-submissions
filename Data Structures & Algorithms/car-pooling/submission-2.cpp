class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        priority_queue<std::pair<int, int>, vector<std::pair<int, int>>,
                       greater<std::pair<int, int>>>
            pq;
        
        int curr_pass = 0;
        for(auto& trip: trips){
            int pass = trip[0];
            int from = trip[1];
            int to  = trip[2];

            while(!pq.empty() && pq.top().first<=from){
                curr_pass -= pq.top().second;
                pq.pop();
            }

            curr_pass += pass;
            pq.push({to,pass});
            if(curr_pass>capacity) return false;
        }

        return true;
    }
};