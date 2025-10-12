class Solution {
public:
    void loki(vector<int>& candidates, int target, int sum, int n, vector<vector<int>>& ans, vector<int>& q, int idx){
        if(sum==target){
            ans.push_back(q);
            return;
        }
        if(sum>target || idx >=n) return;
        q.push_back(candidates[idx]);
        loki(candidates, target, sum+candidates[idx], n, ans, q, idx);
        q.pop_back();
        loki(candidates, target, sum, n, ans, q, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> q;
        loki(candidates, target, 0, n, ans, q, 0);
        return ans;
    }
};