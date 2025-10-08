class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> g;
        for (auto& e : edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }

        vector<int> oddNodes;
        for (int i = 1; i <= n; i++) {
            if (g[i].size() % 2 == 1) oddNodes.push_back(i);
        }

        if (oddNodes.size() == 0) return true;

        if (oddNodes.size() == 2) {
            int a = oddNodes[0], b = oddNodes[1];
            if (!g[a].count(b)) return true;
            for (int c = 1; c <= n; c++) {
                if (c != a && c != b && !g[a].count(c) && !g[b].count(c)) 
                    return true;
            }
            return false;
        }

        if (oddNodes.size() == 4) {
            int a = oddNodes[0], b = oddNodes[1], c = oddNodes[2], d = oddNodes[3];
            return (!g[a].count(b) && !g[c].count(d)) ||
                   (!g[a].count(c) && !g[b].count(d)) ||
                   (!g[a].count(d) && !g[b].count(c));
        }

        return false;
    }
};