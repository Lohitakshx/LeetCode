class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx = n-1; idx>=0; idx--){
            for(int pre = idx-1; pre>=-1; pre--){
                int notTake = dp[idx+1][pre+1];
                int take = 0;
                if(pre==-1 || nums[idx]>nums[pre]){
                    take = 1+dp[idx+1][idx+1];
                }
                dp[idx][pre+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};