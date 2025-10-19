class Solution {
  public:
  
    void loki(vector<int> &arr, int idx, vector<int> &curr, set<vector<int>> &ans ){
        if(idx == arr.size()) {
            ans.insert(curr);
            return;
        }
        loki(arr, idx+1, curr, ans);
        curr.push_back(arr[idx]);
        loki(arr, idx+1, curr,ans);
        curr.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<int>curr;
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        loki(arr,0, curr, ans);
        vector<vector<int>> ans1;
        for(auto i : ans) ans1.push_back(i);
        return ans1;
    }
};