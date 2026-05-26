class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int k = r;
        while(l<=r){
            int mid = (l+r)/2;
            if(can_load(mid,piles,h)){
                k = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return k;
    }
private:
    bool can_load(int w,vector<int>& piles, int h){
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i< piles.size(); i++){
            sum += (piles[i]+w-1)/w;
            if(sum>h){
                return false;
            }
        }
        return true;
    }
};
