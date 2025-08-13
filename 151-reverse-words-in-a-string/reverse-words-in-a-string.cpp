class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for(int i = 0; i< s.size(); i++){
            if(s[i]==' ') continue;
            string temp;
            while(i<s.size() && s[i]!=' '){
            temp+=s[i];
            i++;
            }
            if(ans.empty()) ans = temp;
            else ans = temp + " " + ans;
        }
        return ans;
    }
};