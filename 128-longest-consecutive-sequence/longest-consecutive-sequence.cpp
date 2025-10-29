class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> arr(nums.begin(), nums.end());
        int ans = 0;
        for(auto i : arr){
            if(arr.find(i-1)==arr.end()){
                int curr = i;
                int count = 1;
                while(arr.find(curr+1)!=arr.end()){
                    count++;
                    curr++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};