class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord)) return 0; // endWord not in list
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string temp = q.front().first;
            int step = q.front().second;
            q.pop();
            for(int i = 0; i<temp.size(); i++){
                char original = temp[i];
                for(char c = 'a'; c<= 'z'; c++){
                    if(c == original) continue; // skip same char
                    temp[i] = c;
                    if(s.count(temp)) {
                        if(temp == endWord) return step+1;
                        q.push({temp, step+1});
                        s.erase(temp);
                    }
                }
                temp[i] = original;
            }
        }
        return 0;
    }
};