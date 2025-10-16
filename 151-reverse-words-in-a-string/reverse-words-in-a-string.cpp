#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.length() - 1;

        // Step 1: Trim leading and trailing spaces
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;

        string word = "";
        string ans = "";

        // Step 2: Traverse and build words
        while (left <= right) {
            char ch = s[left];
            if (ch != ' ') {
                word += ch;
            } else if (word != "") {  // encountered space after a word
                // prepend word to answer
                if (!ans.empty()) ans = word + " " + ans;
                else ans = word;
                word = "";
            }
            left++;
        }

        // Step 3: Add the last word
        if (!word.empty()) {
            if (!ans.empty()) ans = word + " " + ans;
            else ans = word;
        }

        return ans;
    }
};
