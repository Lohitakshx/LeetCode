class Solution {
public:
    bool isPalindrome(int x) {
        string ans  = to_string(x);
        string temp = ans;
        reverse(ans.begin(), ans.end());
        return  ans == temp;
    }
};