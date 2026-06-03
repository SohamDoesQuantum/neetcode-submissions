class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> min_cost(n, INT_MAX);
        vector<int> inMST(n, 0);
        vector<int> parent(n, -1);
        min_cost[0] = 0;
        int total_cost = 0;
        for (int step = 0; step < n; step++) {
            int curr_node = -1;
            int min_val = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (inMST[i] == 0 && min_cost[i] < min_val) {
                    min_val = min_cost[i];
                    curr_node = i;
                }
            }

            inMST[curr_node] = 1;
            total_cost += min_val;
            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (inMST[neighbor] == 0) {
                    int cost_to_connect = abs(points[curr_node][0] - points[neighbor][0]) +
                                          abs(points[curr_node][1] - points[neighbor][1]);
                    if (cost_to_connect < min_cost[neighbor]) {
                        min_cost[neighbor] = cost_to_connect;
                    }
                }
            }
        }
        return total_cost;
    }
};
