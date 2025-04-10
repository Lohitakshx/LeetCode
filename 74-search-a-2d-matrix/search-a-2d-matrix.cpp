class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = n*m-1;

        while(left<=right){
            int mid = (left+right)/2;
            int val = matrix[mid/m][mid%m];
            if(val==target) return true;
            else if(val<target) left=mid+1;
            else right = mid-1;
        }
        return false;
    }
};