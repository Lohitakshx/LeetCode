// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> map;
//         vector<int> ans;
//         for(auto i : nums) set.insert(target-i);
//         for(int i = 0; i<nums.size(); i++){
//             if(set.find(nums[i])!=set.end())
//         }
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i<nums.size()-1; i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target) return {i , j};
            }
        }
        return {};
    }
};