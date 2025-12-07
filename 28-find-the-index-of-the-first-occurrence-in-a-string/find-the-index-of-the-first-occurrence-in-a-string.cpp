class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        int last = 0;
        for(int i  = 0; i<h; i++){
            if(haystack[i]==needle[last]){
                last++;
            }
            else{
                i = i-last;
                last = 0;
            }
            if(last == n){
                return i-last+1;
            }
        } 
        return -1;
    }
};