#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        queue<pair<int, vector<string>>> q; // index, current partition
        q.push({0, {}});

        while(!q.empty()) {
            auto [idx, path] = q.front(); q.pop();

            if(idx == n) {
                ans.push_back(path);
                continue;
            }

            for(int i = idx; i < n; i++) {
                if(isPalindrome(s, idx, i)) {
                    auto newPath = path;
                    newPath.push_back(s.substr(idx, i - idx + 1));
                    q.push({i + 1, newPath});
                }
            }
        }

        return ans;
    }
};
