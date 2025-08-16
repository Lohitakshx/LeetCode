class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el;
        int n  = nums.size();
        for(int i = 0; i< n; i++){
            if(count == 0){
                el = nums[i];
                count = 1;
            }
            else if(el==nums[i]) count++;
            else count--;
        }
        return el;
    }
};