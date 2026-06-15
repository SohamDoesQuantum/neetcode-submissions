class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});
        string s = "";
        while (pq.size()) {
            auto [count, chr] = pq.top();
            pq.pop();
            int n = s.size();
            if (n > 1 && s[n - 1] == chr && s[n - 2] == chr) {
                if (pq.empty()) {
                    break;
                } else {
                    auto [count2, chr2] = pq.top();
                    pq.pop();
                    s += chr2;
                    if (count2 - 1) {
                        pq.push({count2 - 1, chr2});
                    }
                }
            } else {
                s += chr;
                count--;
            }
            if (count) {
                pq.push({count, chr});
            }
        }

        return s;
    }
};