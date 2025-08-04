class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int sum2 = nums[0];
        for(int i = 1; i<nums.size(); i++){
            sum=max(nums[i], sum+nums[i]);
            sum2 = max(sum2, sum);
        }
        return sum2;
    }
};