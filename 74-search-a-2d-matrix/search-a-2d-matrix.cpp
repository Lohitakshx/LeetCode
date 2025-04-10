class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (vector<int> row : matrix) {
            for (int val : row) {
                if (val == target) return true;
            }
        }
        return false;
    }
};
