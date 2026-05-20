class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;
        int i = 0;
        int j = n-1;
        while(i<j){
            int h = min(heights[i],heights[j]);
            int w = j-i;
            area = max(area, h*w);
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return area;
    }
};
