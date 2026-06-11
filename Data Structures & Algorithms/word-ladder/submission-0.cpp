class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;
        unordered_set<string> words;
        unordered_set<string> reached;
        unordered_set<char> chr;
        for (string& word : wordList) {
            words.insert(word);
            for (char c : word) chr.insert(c);
        }
        queue<string> q;
        q.push(beginWord);
        words.insert(beginWord);
        reached.insert(beginWord);
        int steps = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if(curr == endWord) return steps;
                vector<string> combinations;
                generate(curr, words, chr, combinations);
                for (string s : combinations)
                    if (reached.count(s) == 0) {
                        q.push(s);
                        reached.insert(s);
                    }
              
            }
            steps++;
        }
        return 0;
    }
    void generate(string& curr, unordered_set<string>& words, unordered_set<char>& chr,
                  vector<string>& combinations) {
        for (int i = 0; i < curr.size(); i++) {
            for (auto& it : chr) {
                string temp = curr;
                temp[i] = it;
                if (words.count(temp)) {
                    combinations.push_back(temp);
                }
            }
        }
    }
};
