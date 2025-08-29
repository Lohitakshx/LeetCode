class Solution {
public:
    int uniquePaths(int m, int n) {
        long long sum = n+m-1;
        long long ans = 1;
        for(int i = 1; i<m; i++){
            ans = ans * (sum-m+i)/i;
        }    
        return ans;
    }
};