class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& temp, int idx) {

        ans.push_back(temp);  // ✅ every state is a valid subset

        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);        // choose
            solve(nums, ans, temp, i + 1);  // explore
            temp.pop_back();                // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, ans, temp, 0);
        return ans;
    }
};
