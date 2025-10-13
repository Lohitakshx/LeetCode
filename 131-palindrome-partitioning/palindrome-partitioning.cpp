class Solution {
public:
    bool isPalindrome(string &arr){
        string copy = arr;
        reverse(arr.begin(), arr.end());
        return arr == copy;
    }
    void loki (string s, int idx, vector<vector<string>>& ans, vector<string>& q){
        if(idx == s.length()){
            ans.push_back(q);
            return;
        } 
        for(int i = idx; i<s.length(); i++){
            string temp = s.substr(idx, i-idx+1);
            if(isPalindrome(temp)){
                 q.push_back(temp);
                 loki(s, i+1, ans, q);
                 q.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> q;
        loki(s, 0, ans, q);
        return ans;
    }
};