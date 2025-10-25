class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ansSet;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            for(int j = i+1; j<n; j++){
                unordered_set<long long> s;
                for(int k = j+1; k<n; k++){
                    long long comp =(long long) target - nums[i] - nums[j] - nums[k];
                    if(s.find(comp)!=s.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)comp};
                        sort(temp.begin(), temp.end());
                        ansSet.insert(temp);
                    }
                    s.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(ansSet.begin(), ansSet.end());
        return ans;
    }
};