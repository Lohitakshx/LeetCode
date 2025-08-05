class Solution {
public:
    vector<int> getRow(int r) {
        r++;
        vector<int> ans;
        ans.push_back(1);
        long long loki = 1;
        for(int i = 1; i<r; i++){
            loki = loki * (r-i) / i ;
            ans.push_back(loki);
        }
        return ans;
    }
};