class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string pre = strs[0];
        int len = pre.size();

        for(int i = 1; i<strs.size(); i++){
            string temp = strs[i];
            while(len>temp.size() || pre != temp.substr(0, len)){
                len--;
                if(len==0) return "";
                pre = pre.substr(0, len);
            }
        }
        return pre;
    }
};