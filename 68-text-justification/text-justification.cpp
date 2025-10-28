class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int l = 0, n = words.size();

        while (l < n) {
            int len = words[l].size();
            int r = l + 1;

            // find right boundary
            while (r < n && len + 1 + words[r].size() <= maxWidth) {
                len += 1 + words[r].size();
                r++;
            }

            string line = "";
            int numOfSpaces = r - l - 1;

            // last line or single word
            if (r == n || numOfSpaces == 0) {
                for (int k = l; k < r; k++) {
                    line += words[k];
                    if (k != r - 1) line += ' ';
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int totalSpaces = maxWidth;
                for (int p = l; p < r; p++) totalSpaces -= words[p].size();
                int gaps = totalSpaces / numOfSpaces;
                int extra = totalSpaces % numOfSpaces;

                for (int x = l; x < r - 1; x++) {
                    line += words[x];
                    line += string(gaps + (x - l < extra ? 1 : 0), ' ');
                }
                line += words[r - 1];
            }

            ans.push_back(line);
            l = r;
        }
        return ans;
    }
};
