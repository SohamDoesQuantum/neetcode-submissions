class Solution {
   public:
    vector<int> merge(vector<int>& left, vector<int>& right) {
        
        vector<int> ans;
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                ans.push_back(left[i++]);
            } else {
                ans.push_back(right[j++]);
            }
        }
        while (i < left.size()) {
                ans.push_back(left[i++]);
            }
            while (j < right.size()) {
                ans.push_back(right[j++]);
            }
            return ans;
    }
        vector<int> sortArray(vector<int> & nums) {
            int n = nums.size();
            if (n <= 1) return nums;
            vector<int> left(nums.begin(), nums.begin() + n / 2);
            vector<int> right(nums.begin() + n / 2, nums.end());

            left = sortArray(left);
            right = sortArray(right);
            return merge(left, right);
        }
    };