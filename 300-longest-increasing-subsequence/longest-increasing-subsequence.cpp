class Solution {
public:
    int solve(vector<int> &nums, int n, int idx, int pre,vector<vector<int>> &dp){
        if(idx==n) return 0;
        if(dp[idx][pre+1]!=-1) return dp[idx][pre+1];
        int notTake = solve(nums, n, idx+1, pre, dp);
        int take = 0;
        if(pre==-1 || nums[idx]>nums[pre]){
            take = 1+solve(nums, n, idx+1, idx, dp);
        }
        return dp[idx][pre+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int idx = 0;
        int pre = -1;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, n, idx, pre ,dp);
    }
};