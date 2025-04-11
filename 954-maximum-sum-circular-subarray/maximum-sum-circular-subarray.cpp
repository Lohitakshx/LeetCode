class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = nums[0];
        int min_sum = nums[0];
        int n = nums.size();
        int curr_sum_max = nums[0];
        int curr_sum_min = nums[0];
        int total = nums[0];

        for (int i = 1; i <n; ++i) {        
            curr_sum_max = max(nums[i], curr_sum_max+nums[i]);
            max_sum = max(max_sum, curr_sum_max); 

            curr_sum_min = min(nums[i], curr_sum_min+ nums[i]);
            min_sum = min(min_sum , curr_sum_min);

            total += nums[i];


        }
        if(max_sum<0) return max_sum;
        return max(max_sum, total-min_sum);
    }
};