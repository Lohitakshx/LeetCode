class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n!=m) return false;
        unordered_map<char , int> arr;
        unordered_map<char , int> brr;
        for(int i = 0 ; i< n; i++){
            arr[s[i]]++;
            brr[t[i]]++;
        }
        for(auto c : s)if(arr[c]!= brr[c]) return false;
        return true;
    }
};