class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<int>cost(n,INT_MAX);
        for (vector<int>& v : flights) {
            int from = v[0];
            int to = v[1];
            int price = v[2];
            adj[from].push_back({to, price});
        }
        int total_cost = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;
        while (q.size() && stops <= k) {
            int size = q.size();
            while (size--) {
                auto [curr_node, curr_cost] = q.front();
                q.pop();
                for (const auto& neighbor : adj[curr_node]) {
                    int next_node = neighbor.first;
                    int price = neighbor.second;

                    if (curr_cost + price < cost[next_node]) {
                        cost[next_node] = curr_cost + price;
                        q.push({next_node, cost[next_node]});
                    }
                }
                
            }
            stops++;
        }
        if (cost[dst] == INT_MAX) return -1;
        return cost[dst];
    }
};
