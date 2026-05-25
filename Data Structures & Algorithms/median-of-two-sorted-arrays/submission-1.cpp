class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int i = 0, j = nums1.size();
        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;
        while (i <= j) {
            int mid = (i + j) / 2;
            int mid1 = half - mid;
            int Aleft = (mid > 0) ? nums1[mid-1] : INT_MIN;
            int Aright = (mid < nums1.size()) ? nums1[mid] : INT_MAX;
            int Bleft = (mid1 > 0) ? nums2[mid1-1] : INT_MIN;
            int Bright = (mid1 < nums2.size()) ? nums2[mid1] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2) {
                    return max(Aleft, Bleft);
                } else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            }
            else if (Aleft > Bright) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return -1;
    }
};
