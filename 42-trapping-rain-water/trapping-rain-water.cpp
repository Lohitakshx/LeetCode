class Solution {
public:
    int trap(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int lm = nums[l];
        int rm = nums[r];
        int ans = 0;
        while(l<r){
            if(lm<rm){
                l++;
                lm = max(nums[l], lm);
                ans+=lm-nums[l];
            }
            else{
                r--;
                rm = max(nums[r], rm);
                ans+=rm-nums[r];
            }
        }
        return ans;
    }
};