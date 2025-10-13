class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> numss;
        sort(nums.begin(), nums.end());   
        
        for(int mask = 0; mask<(1<<nums.size()); mask++){
            vector<int> temp;
            for(int i = 0; i<nums.size(); i++){
                if(mask & (1<<i)) temp.push_back(nums[i]);
            }
            numss.insert(temp);
        }
        for(auto i : numss) ans.push_back(i);
        return ans;
    }
};
