class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> ls;
        stack<int> rs;
        vector<int> l(heights.size());
        vector<int> r(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            while (!ls.empty() && heights[ls.top()] >= heights[i]) {
                ls.pop();
            }
            if (ls.empty()) {
                l[i] = -1;
            } else {
                l[i] = ls.top();
            }
            ls.push(i);
            int j = heights.size() - 1 - i;
            while (!rs.empty() && heights[rs.top()] >= heights[j]) {
                rs.pop();
            }
            if (rs.empty()) {
               r[j] = heights.size();
            }
            else{
                r[j] = rs.top();
            }
            rs.push(j);
        }
        int area = 0;
        for(int i = 0; i<heights.size(); i++){
            area = max(area, (r[i]-l[i]-1)*heights[i]);
        }
        return area;
    }
};
