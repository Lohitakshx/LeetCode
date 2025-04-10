class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        queue<int> q;
        unordered_set<int> visited;

        q.push(0);
        visited.insert(0);
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            ++steps;

            for (int i = 0; i < size; ++i) {
                int curr = q.front(); q.pop();

                for (int coin : coins) {
                    int next = curr + coin;
                    if (next == amount) return steps;
                    if (next < amount && visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }

        return -1; // not possible
    }
};
