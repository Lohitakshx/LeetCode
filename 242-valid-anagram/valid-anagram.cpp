class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;
        unordered_map<char , int> arr;
        for(int i = 0 ; i< n; i++){
            arr[s[i]]++;
        }
        for(int i = 0; i<n; i++){
            arr[t[i]]--;
            if(arr[t[i]]<0) return false;
        }
        return true;
    }
};