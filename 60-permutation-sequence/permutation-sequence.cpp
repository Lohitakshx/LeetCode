#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++)
            nums.push_back(i);
        
        // generate permutations k-1 times
        for(int i = 1; i < k; i++)
            next_permutation(nums.begin(), nums.end());
        
        // convert the k-th permutation to string
        string ans = "";
        for(int num : nums)
            ans += to_string(num);
        
        return ans;
    }
};
