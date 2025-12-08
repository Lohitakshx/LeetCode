class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];
        for(int i  = 1 ; i< nums.size(); i++){
            int tempMax = max(nums[i], max(nums[i]* minProd, nums[i]* maxProd));
            int tempMin = min(nums[i], min(nums[i]* minProd, nums[i]* maxProd));

            maxProd = tempMax;
            minProd = tempMin;

            ans = max(ans, maxProd);
        }
        return ans;
    }
};