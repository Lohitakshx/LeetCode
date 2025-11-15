class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookie =s.size()-1;
        int child = g.size()-1;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;

        while(child>=0 && cookie>=0){
            if(g[child] <= s[cookie]){
                ans++;
                child--, cookie--;
            }
            else child--;
        }
        return ans;
    }
};