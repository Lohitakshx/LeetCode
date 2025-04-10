class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        int column_size = matrix[0].size();

        int left = 0;
        int right = row_size * column_size - 1;

        while(left<=right){
            int mid = (left+right)/2;
            int val = matrix[mid / column_size][mid % column_size];
            if(val==target) return true;
            else if(val<target) left=mid+1;
            else right = mid-1;
        }
        return false;
    }
};