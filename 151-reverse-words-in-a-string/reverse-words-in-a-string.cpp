class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        string token;
        stringstream ss(s);
        while(ss>>token){
            tokens.push_back(token);
        }
        string ans;
        for(int i = tokens.size()-1; i>=0; i--){
            ans+=tokens[i];
            if(i>0) ans+= ' ';
        }

        return ans;
    }
};