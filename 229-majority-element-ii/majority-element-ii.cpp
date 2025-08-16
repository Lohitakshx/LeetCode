class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int mi = (int)n/3+1;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(int i = 0 ;i<n; i++){
            if(count1==0&&nums[i]!=el2){
                el1 = nums[i];
                count1++;
            }
            else if(count2==0 && el1 !=nums[i]){
                el2 = nums[i];
                count2++;
            }
            else if(nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
            else{
                count1--, count2--;
            }
            
        }
        int p = 0, q = 0;
        for(auto i: nums){
            if(i==el1) p++;
            else if(i==el2) q++;
        }
        if(p>=mi)ans.push_back(el1);
        if(q>=mi)ans.push_back(el2);
        
        return ans;
    }
};