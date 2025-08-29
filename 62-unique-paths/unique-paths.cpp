class Solution {
public:
    int uniquePaths(int m, int n) {
        long long top = n+m-2;
        long long bottom = n-1;
        long long ans = 1;
        for(int i = 1; i<=bottom; i++){
            ans = ans * (top-bottom+i)/i;
        }    
        return ans;
    }
};