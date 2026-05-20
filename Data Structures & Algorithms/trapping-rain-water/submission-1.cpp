class Solution {
public:
    int trap(vector<int>& height) {
        int amt = 0;
        int max_seen1 = -1;
        int max_seen2 = -1;
        int n = height.size();
        vector<int> right (n);
        vector<int> left (n);
        for(int i = 0; i< n; i++){
            left[i] = max_seen1;
            if(height[i]>max_seen1){
                max_seen1 = height[i];
            }
            int j = n-1-i;
            right[j] = max_seen2;
            if(height[j]>max_seen2){
                max_seen2 = height[j];
            }
        }

        for(int i  = 0; i<n; i++){
            if(left[i]>=height[i] && right[i]>=height[i]){
                amt += min(left[i],right[i])-height[i];
            }
        }
        return amt;
       
       

    }
};
