class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        vector<int> arr3(m + n);
        int left = 0, right = 0, index = 0;

        while (left < m && right < n) {
            if (arr1[left] <= arr2[right]) {
                arr3[index++] = arr1[left++];
            } else {
                arr3[index++] = arr2[right++];
            }
        }
        while (left < m) {
            arr3[index++] = arr1[left++];
        }

        while (right < n) {
            arr3[index++] = arr2[right++];
        }
        for (int i = 0; i < m + n; i++) {
            arr1[i] = arr3[i];
        }
    }
};
