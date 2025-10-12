class Solution {
public:
    void solve(int idx, int n, vector<int>& candidates, int target,
               int sum, vector<int>& q, vector<vector<int>>& ans) {

        // base case
        if (sum == target) {
            ans.push_back(q);
            return;
        }
        if (idx >= n || sum > target) return;  // stop exploring

        // ✅ CHOOSE current element
        q.push_back(candidates[idx]);
        solve(idx + 1, n, candidates, target, sum + candidates[idx], q, ans);
        q.pop_back();

        // ✅ NOT CHOOSE current element
        // skip all duplicates of the current number before next recursion
        int nextIdx = idx + 1;
        while (nextIdx < n && candidates[nextIdx] == candidates[idx]) {
            nextIdx++;
        }
        solve(nextIdx, n, candidates, target, sum, q, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> q;
        solve(0, candidates.size(), candidates, target, 0, q, ans);
        return ans;
    }
};
