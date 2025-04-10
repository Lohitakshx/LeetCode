class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix) {
            if (target >= row.front() && target <= row.back()) {
                if (binary_search(row.begin(), row.end(), target)) return true;
            }
        }
        return false;
    }
};
