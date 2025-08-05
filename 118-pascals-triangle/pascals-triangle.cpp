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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalans;
        for(int i = 0; i<numRows; i++){
            finalans.push_back(getRow(i));
        }
        return finalans;
    }
};