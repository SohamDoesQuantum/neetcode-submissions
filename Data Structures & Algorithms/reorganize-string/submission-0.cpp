class Solution {
   public:
    string reorganizeString(string s) {
        vector<int> freq(26);
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            freq[idx]++;
        }
        using elem = pair<int, char>;
        priority_queue<elem> pq;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > (s.length() + 1) / 2) return "";
            if (freq[i]) pq.push({freq[i], static_cast<char>(i + 'a')});
        }
        queue<pair<int, char>> q;
        string txt = "";
        elem prev = {0, '#'};
        while (!pq.empty()) {

            auto [frq, ch] = pq.top();
            txt.push_back(ch);
            pq.pop();
            if (prev.first > 0) {
                pq.push(prev);
            }
            frq--;
            prev = {frq,ch};
        }
        return txt;
    }
};