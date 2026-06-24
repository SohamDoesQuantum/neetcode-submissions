class Solution {
   public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') return false;

        int idx = 0;
        vector<int> reachable(n);
        reachable[0] = 1;
        while (idx < n) {
            if (s[idx] == '0' && reachable[idx]) {
                for (int jump = idx + minJump; jump <= min(idx + maxJump, n - 1); jump++) {
                    if (s[jump] == '0') reachable[jump] = 1;
                }
            }
            idx++;
        }
        return reachable[n-1] == 1;
    }
};