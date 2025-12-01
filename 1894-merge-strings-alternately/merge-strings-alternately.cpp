class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1==0) return word2;
        else if(len2 == 0) return word1;
        int n = min(len1, len2);
        for(int i = 0; i<n; i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        if(len1==len2) return ans;
        else if(len1<len2) for(int i = n; i<len2; i++) ans+=word2[i];
        else if(len1>len2) for(int i = n; i<len1; i++) ans+=word1[i];
        return ans;
    }
};