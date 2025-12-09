class Solution {
public:
    void solve(vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& ans,int idx, int sum){
        if(sum==target) {
            ans.push_back(temp);
            return;
            }
        for(int i = idx; i<nums.size(); i++){
            if(nums[i]>target-sum) break;
            temp.push_back(nums[i]);
            solve(nums, target, temp, ans, i, sum+nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(nums, target, temp, ans, 0, 0);
        return ans;
    }
};