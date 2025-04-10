class Solution {
public:
    int loki(int i , vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()) return 1;
        if (dp[i] != -1) return dp[i];

        
        dp[i] = max(nums[i]+loki(i+2, nums, dp), loki(i+1, nums, dp));
        return dp[i];
    };
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return loki(0,nums,dp)-1;
        
    }
};