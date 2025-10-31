class Solution {
public:
    int maxArea(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int ans = 0;
        while(l<r){
            int water = min(nums[l], nums[r]) * (r-l);
            ans = max(ans, water);
            if(nums[l]<nums[r]) l++;
            else if(nums[l]> nums[r]) r--;
            else l++, r--;
        }
        return ans; 
    }
};