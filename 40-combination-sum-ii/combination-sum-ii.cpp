
class Solution {
public:
    void loki(vector<int>& candidates, int target, int sum, int n, vector<vector<int>>& ans, vector<int>& q, int idx){
        if(sum==target){
            ans.push_back(q);
            return;
        }
        for(int i = idx ; i<n; i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target-sum) break;
            q.push_back(candidates[i]);
            loki(candidates, target, sum+candidates[i],n, ans, q, i+1);
            q.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> q;
        sort(candidates.begin(), candidates.end());
        loki(candidates, target, 0, n, ans, q, 0);
        return ans;
    }
};