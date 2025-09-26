class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int mask = 0; mask<(1<<nums.size()); mask++){
            vector<int> temp;
            for(int i = 0; i<nums.size(); i++){
                if(mask & (1<<i)) temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};