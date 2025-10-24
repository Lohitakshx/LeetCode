class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1, 0), curr(n+1, 0);
        for(int idx = n-1; idx>=0; idx--){
            for(int pre = idx-1; pre>=-1; pre--){
                int notTake = next[pre+1];
                int take = 0;
                if(pre==-1 || nums[idx]>nums[pre]){
                    take = 1+next[idx+1];
                }
                curr[pre+1] = max(take, notTake);
            }
            next = curr;
        }
        return next[0];
    }
};