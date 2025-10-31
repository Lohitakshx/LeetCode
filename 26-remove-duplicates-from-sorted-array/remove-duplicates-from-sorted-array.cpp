class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int count = nums.size();
        int i = 0;
        while(i<nums.size()){
            if(st.find(nums[i])!=st.end()){
                nums.erase(nums.begin()+i);
                count--;

            }
            else {
                st.insert(nums[i]); i++;}
                }
        return count;
    }
};