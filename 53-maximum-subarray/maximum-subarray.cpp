class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int current_max = nums[0];
        int max_sum = nums[0];
        for(int i = 1; i<n; i++){
            current_max = max(nums[i] , current_max +nums[i]);
            max_sum = max(max_sum, current_max);
        }
        return max_sum;
    }
};