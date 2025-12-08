class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        vector<int> ans;
    
        for(int i = 0; i<nums.size(); i++){
            if(count1 == 0 && nums[i]!=el2){
                count1 = 1;
                el1 = nums[i];
            }
            else if(count2 == 0 && nums[i]!=el1){
                count2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1) count1++;
            else if(nums[i] == el2) count2++;
            else count1--, count2--;
        }   
        int a = 0, b = 0;
        for(auto i : nums){
            if (i==el1) a++;
            else if(i==el2) b++;
        }
        if(a>nums.size()/3) ans.push_back(el1);
        if(b>nums.size()/3) ans.push_back(el2);
        return ans;
    }
};