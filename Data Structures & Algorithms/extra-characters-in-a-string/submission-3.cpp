#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    Node *links[26] = {nullptr};
    bool flag = false;

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
    void put(char ch, Node *node) { links[ch - 'a'] = node; }
    Node *get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Solution {
private:
    Node *root;

    void insert(const string &word) {
        Node *node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }

public:
    Solution() { root = new Node(); }

    int minExtraChar(string s, vector<string>& dictionary) {
        for (const auto &word : dictionary) {
            insert(word);
        }
        
        vector<int> dp(s.size() + 1, -1);
        dp[s.size()] = 0; 
        
        return search(0, s, dp);
    }

    int search(int i, const string &s, vector<int> &dp) {
        if (dp[i] != -1) return dp[i];

        // Case 1: Skip the current character s[i] (counts as 1 extra character)
        int res = 1 + search(i + 1, s, dp);

        // Case 2: Try to match words starting at index i using the Trie directly
        Node *node = root;
        for (int j = i; j < s.size(); j++) {
            if (!node->containsKey(s[j])) {
                // If the character prefix doesn't exist in the Trie, 
                // no larger substring starting here can match anything in the dictionary.
                break; 
            }
            
            node = node->get(s[j]); // Move deeper into the Trie
            
            if (node->isEnd()) {
                // Found a valid word spanning from index i to j
                res = min(res, search(j + 1, s, dp));
            }
        }

        return dp[i] = res;
    }
};