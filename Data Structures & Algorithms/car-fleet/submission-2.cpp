class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> st;
        vector<pair<int,  int>> ps(position.size());
        for(int i = 0; i< position.size();i++){
            ps[i] = {position[i],speed[i]};
        }
        sort(ps.begin(),ps.end());
        for(int i = ps.size()-1; i>=0; i--){
            float time = (float)(target-ps[i].first)/ps[i].second;
            if(st.empty() || time>st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
