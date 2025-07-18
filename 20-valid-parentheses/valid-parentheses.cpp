class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracket = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
        stack<char> arr;
        for(auto c: s){
            if(c=='('||c=='{'||c=='[') arr.push(c);
            else{
                if (arr.empty() || arr.top() != bracket[c]) return false;
                arr.pop();
            }
        }
        return arr.empty();
    }
};