class Solution {
  public:
  
    void loki(vector<int> &arr, int idx, vector<int>& curr, vector<vector<int>> &ans ){
        if(idx == arr.size()) {
            ans.push_back(curr);
            return;
        }
        loki(arr, idx+1, curr, ans);
        curr.push_back(arr[idx]);
        loki(arr, idx+1, curr,ans);
        curr.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int>curr;
        vector<vector<int>> ans;
        loki(arr,0, curr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};