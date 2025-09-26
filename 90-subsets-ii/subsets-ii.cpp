class Solution {
  public:
  
    void loki(vector<int> &arr, int idx, vector<int> curr, vector<vector<int>> &ans ){
        ans.push_back(curr);
        for(int i =idx; i<arr.size(); i++){
            if(i!=idx && arr[i]==arr[i-1]) continue;
            curr.push_back(arr[i]);
            loki(arr, i+1, curr, ans);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<int>curr;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        loki(arr,0, curr, ans);
        return ans;
    }
};