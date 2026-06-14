class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int i = 0;
        int time = tasks[0][0];
        vector<int> res;
        while (i < tasks.size() || pq.size()) {
            while (i < tasks.size() && time >= tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            if (pq.size() == 0) {
                time = tasks[i][0];
            } else {
                auto [proc_time, idx] = pq.top();
                pq.pop();
                time += proc_time;
                res.push_back(idx);
            }
        }
        return res;
    }
};