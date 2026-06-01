class Solution {
public:
    
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        q.push("0000");

        unordered_set<string> visited;
        for(string d : deadends) visited.insert(d);
        if(visited.count("0000")) return -1;
        bool target_found = false; int turn = 0;

        while(!q.empty()){
            int p = q.size();
            
            while(p--){
                string comb = q.front();
                q.pop();
                if(comb==target) return turn;
                vector<string> children;
                generate(children,comb);
                for(string c : children){
                    if(visited.find(c)==visited.end()){
                        q.push(c);
                        visited.insert(c);
                    }
                }
            }
            turn++;
        }
        return -1;
    }

    void generate(vector<string>&children, string& comb){
        for(int i = 0; i<comb.size();i++){
            int x = comb[i]-'0';
            string a = comb.substr(0,i)+to_string((x+1)%10)+comb.substr(i+1);
            string b = comb.substr(0,i)+to_string((x-1+10)%10)+comb.substr(i+1);
            children.push_back(a); children.push_back(b); 
        }
    }
};