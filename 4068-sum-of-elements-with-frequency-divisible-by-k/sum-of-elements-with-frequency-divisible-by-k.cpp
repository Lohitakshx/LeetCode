class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (auto i : nums) {
            hash[i]++;  
        }

        int sum = 0;
        for (auto &p : hash) {
            int num = p.first;
            int freq = p.second;
            if (freq % k == 0) {
                sum += num * freq;
            }
        }
        return sum;
    }
};
