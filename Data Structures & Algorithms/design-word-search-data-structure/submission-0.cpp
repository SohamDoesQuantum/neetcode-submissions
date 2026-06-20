struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
    Node* get(char ch) { return links[ch - 'a']; }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void isEnd(){
        flag = true;
    }
};
class WordDictionary {
    Node* root;

   public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
        node->isEnd();
    }
    bool search(string word) {
        return dfs(word,0,root);
    }
    bool dfs(string& word, int index, Node* node){
        if(index >= word.size()){
            return node->flag;
        }
        char ch = word[index];
        if(ch=='.'){
            for(int i = 0; i < 26; i++){
                if(node->containsKey('a'+i)){
                    if(dfs(word,index+1,node->get('a'+i))) 
                        return true;
                }
            }
        }
        else{
            if(node->containsKey(ch)){
                return dfs(word,index+1,node->get(ch));
            }
        }
        return false;
    }
};
