class Solution {
public:
bool wordBreakMemo(string s, unordered_set<string>& dict, int start, vector<int>& dp){
    if(start == s.size()) return true;
    if(dp[start] != -1) return dp[start];

    for(int end = start+1; end <= s.size(); end++){
        string word = s.substr(start, end-start);
        if(dict.count(word) && wordBreakMemo(s, dict, end, dp))
            return dp[start] = 1;
    }
    return dp[start] = 0;
}

bool wordBreak(string s, vector<string>& wordDict){
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> dp(s.size(), -1);
    return wordBreakMemo(s, dict, 0, dp);
}
};