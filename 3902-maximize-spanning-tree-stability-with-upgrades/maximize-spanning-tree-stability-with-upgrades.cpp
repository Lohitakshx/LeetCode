class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        auto check = [&](int target) -> bool {
            vector<int> parent(n), rank(n, 0);
            iota(parent.begin(), parent.end(), 0);

            function<int(int)> find = [&](int x) {
                if (parent[x] != x) parent[x] = find(parent[x]);
                return parent[x];
            };

            auto unite = [&](int x, int y) -> bool {
                x = find(x);
                y = find(y);
                if (x == y) return false;
                if (rank[x] < rank[y]) swap(x, y);
                parent[y] = x;
                if (rank[x] == rank[y]) rank[x]++;
                return true;
            };

            int count = 0;
            int upgradesLeft = k;

            // Add all mandatory edges first
            for (auto& e : edges) {
                int u = e[0], v = e[1], s = e[2], must = e[3];
                if (must == 1) {
                    if (s < target) return false; // mandatory edge too weak
                    if (!unite(u, v)) return false; // mandatory edge cycle
                    count++;
                }
            }

            // Collect all optional edges ≥ target
            vector<tuple<int,int,int>> optional; // (cost, u, v)
            for (auto& e : edges) {
                int u = e[0], v = e[1], s = e[2], must = e[3];
                if (must == 0) {
                    if (s >= target) {
                        optional.emplace_back(0, u, v); // no upgrade needed
                    } else if (s * 2 >= target) {
                        optional.emplace_back(1, u, v); // upgrade needed
                    }
                }
            }

            // Sort optional by upgrade cost (prefer no-upgrade)
            sort(optional.begin(), optional.end());

            for (auto& [cost, u, v] : optional) {
                if (find(u) == find(v)) continue;
                if (cost == 1 && upgradesLeft == 0) continue;
                unite(u, v);
                count++;
                if (cost == 1) upgradesLeft--;
            }

            return count == n-1;
        };

        int low = 1, high = 2e9, ans = -1;

        // Upper bound: max(s, 2*s) for all edges
        for (auto& e : edges) {
            high = max(high, e[2] * 2);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1; // try higher
            } else {
                high = mid - 1; // try lower
            }
        }

        return ans;
    }
};
