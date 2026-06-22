struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Solution {
   private:
    Node* root =  new Node();
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, -1, 1};
    int m, n;

   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        for (auto& i : words) insert(i);
        unordered_set<string> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<int>> visited(m, vector<int>(n, 0));
                string curr;
                if (root->containsKey(board[i][j])) {
                    search(st, i, j, visited, board, root, curr);
                }
            }
        }
        vector<string> ans;
        for (auto& it : st) {
            ans.push_back(it);
        }
        return ans;
    }

    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    void search(unordered_set<string>& st, int i, int j, vector<vector<int>>& visited,
                vector<vector<char>>& board, Node* node, string& curr) {
        node = node->get(board[i][j]);
        curr.push_back(board[i][j]);
        visited[i][j]= 1;
        if (node->isEnd()) st.insert(curr);
        
        for (int d = 0; d < 4; d++) {
            int a = i + dx[d], b = j + dy[d];
            if (a>=0 && a < m && b>=0 && b < n && visited[a][b] == 0) {
                if (node->containsKey(board[a][b])) {
                    search(st, a, b, visited, board, node, curr);
                }
            }
        }
        visited[i][j] = 0;
        curr.pop_back();
    }
};
