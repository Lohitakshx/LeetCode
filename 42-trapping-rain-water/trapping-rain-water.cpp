class Solution {
public:
    int trap(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int ans = 0;
        int lm = nums[l];
        int rm = nums[r];
        while(l<r){
            if(lm>rm) {
                r--;
                rm = max(nums[r], rm);
                ans += rm - nums[r];
                
            }
            else{
                l++;
                lm = max(lm, nums[l]);
                ans+= lm-nums[l];
            }
        }
        return ans;
    }
};