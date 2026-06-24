class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rad,dir;
        for(int i = 0; i<n;i++){
            if(senate[i]=='R'){
                rad.push(i);
            }
            else{
                dir.push(i);
            }
        }
        while(!rad.empty() && !dir.empty()){
            int r_idx = rad.front();
            int d_idx = dir.front();
            rad.pop();
            dir.pop();
            if(r_idx<d_idx){
                rad.push(r_idx+n);
            }
            else{
                dir.push(d_idx+n);
            }
        }

        if(rad.size()){
            return "Radiant";
        }

        return "Dire";
        
    }
};