class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            int a = asteroids[i];
            bool alive = true;
            while(!st.empty() && a<0 && st.top()>0){
                if(st.top() <abs(a)) st.pop();
                else if(st.top() == abs(a)){
                    st.pop();
                    alive =  false;
                    break;
                }
                else{
                    alive = false;
                    break;
                }
            }

            if(alive) st.push(a);
            
        }
        vector<int> a(st.size());
        int n = st.size() - 1;
        while (!st.empty()) {
            a[n--] = st.top();
            st.pop();
        }

        return a;
    }
};