class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
            };
        int ans = 0;
        int i = 0;
        while(i<s.size()){
            if(roman[s[i]]<roman[s[i+1]]){ans = ans+roman[s[i+1]]- roman[s[i]];i++;}
            else ans+=roman[s[i]];
            i++;
        }
        return ans;
    }
};