class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int i =0, j=1;
        int cnt =1;
        while(j<nums.size()){
            if(nums[j]!=nums[i]){
                i++;
                nums[i] = nums[j];
                cnt++;
            }
            j++;
            
        }
        
        return cnt;
    }
};