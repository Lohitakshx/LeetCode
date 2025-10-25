class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
    
        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            unordered_set<int> s;
            for(int j = i+1; j < n; j++) {
                int complement = -nums[i] - nums[j];
                if(s.count(complement)) {
                    res.push_back({nums[i], nums[j], complement});
                    while(j+1 < n && nums[j] == nums[j+1]) j++; // skip duplicates
                }
                s.insert(nums[j]);
            }
        }
    return res;
    }
};