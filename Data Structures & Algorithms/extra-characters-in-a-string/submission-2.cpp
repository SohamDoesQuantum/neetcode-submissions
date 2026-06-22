struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Solution {
   private:
    Node* root;

   public:
    Solution() { root = new Node(); }
    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    bool isPresent(string word) {
        Node* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) return false;
            node = node->get(c);
        }
        if (node->isEnd()) return true;
        return false;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto& it : dictionary){
            insert(it);
        }
        vector<int> dp(s.size() + 1, -1);
        dp[s.size()] = 0;
        search(0, s, dp);
        return dp[0];
    }
    int search(int i, const string& s, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        int res = 1 + search(i + 1, s, dp);
        for (int j = i; j < s.size(); j++) {
            if (isPresent(s.substr(i,j-i+1))) {
                res = min(res, search(j + 1, s, dp));
            }
        }
        dp[i] = res;
        return res;
    }
};