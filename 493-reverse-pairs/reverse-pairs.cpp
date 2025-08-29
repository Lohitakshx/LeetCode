class Solution {
public:
    void merge(vector<int>& arr, int left,int mid, int right){
                         
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
int countAns(vector<int>& arr, int left, int mid, int right){
    int temp = mid + 1;
    int count= 0;
    for (int i = left; i <= mid; i++) {
        while (temp <= right && (long long)arr[i] > 2LL * arr[temp]) temp++;
        count += (temp - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int>& arr, int left, int right){
    int count = 0;
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;
    count+=mergeSort(arr, left, mid);
    count+=mergeSort(arr, mid + 1, right);
    count+=countAns(arr, left, mid, right);
    merge(arr, left, mid, right);
    return count;
}
int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};