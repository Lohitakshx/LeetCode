class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        // vector<int> dp(nums.size());
        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for(int i = 2; i<= nums.size()-1; i++){
            int temp = max(first+nums[i],second);
            first = second;
            second = temp;
            
        }
        return second;
    }
};