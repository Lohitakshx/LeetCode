class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxProd(n), minProd(n);
        
        maxProd[0] = minProd[0] = nums[0];
        int ans = nums[0];
        
        for(int i = 1; i < n; i++) {
            maxProd[i] = max({nums[i], nums[i] * maxProd[i-1], nums[i] * minProd[i-1]});
            minProd[i] = min({nums[i], nums[i] * maxProd[i-1], nums[i] * minProd[i-1]});
            ans = max(ans, maxProd[i]);
        }
        
        return ans;
    }
};
