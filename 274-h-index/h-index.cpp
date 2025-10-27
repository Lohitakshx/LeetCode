class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int count = 0;
        int n =  citations.size();
        for(int i = n-1; i>= 0 ; i--){
            if(count>=citations[i]) return count;
            count++;
        }
        return count;
    }
};