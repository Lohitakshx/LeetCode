class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int q = (b.size()-1) / a.size() + 1;
        string temp = "";
        for(int i = 0; i<q; i++) temp+=a;
        for(int i = 0; i<2; i++){
            if(temp.find(b) != string::npos) return q+i;
            temp+=a;
        }
        return -1;
    }
};