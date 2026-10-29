class Solution {
public:
    int LOG = 17;

    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout, baseMask;
    vector<int> bit;
    int timer = 0;

    // Get bit corresponding to a character
    int getBit(char c) {
        return 1 << (c - 'a');
    }

    // Fenwick Tree: XOR update
    void updateBIT(int idx, int val, int n) {
        for (idx++; idx <= n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    // Fenwick Tree: Prefix XOR query
    int queryBIT(int idx) {
        int ans = 0;

        for (idx++; idx > 0; idx -= idx & -idx) {
            ans ^= bit[idx];
        }

        return ans;
    }

    // Range XOR update
    void rangeUpdate(int l, int r, int val, int n) {
        updateBIT(l, val, n);

        if (r + 1 < n) {
            updateBIT(r + 1, val, n);
        }
    }

    // Get current root-to-node mask
    int getPrefix(int u) {
        return baseMask[u] ^ queryBIT(tin[u]);
    }

    // Find LCA using Binary Lifting
    int LCA(int u, int v) {

        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i))
                u = up[i][u];
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));

        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        baseMask.assign(n, 0);

        bit.assign(n + 1, 0);

        // Build tree
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Iterative DFS to avoid recursion stack overflow
        vector<tuple<int, int, int>> st;
        st.push_back({0, -1, 0});

        while (!st.empty()) {

            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {

                tin[u] = timer++;

                up[0][u] = (p == -1 ? u : p);

                if (p != -1) {
                    depth[u] = depth[p] + 1;
                    baseMask[u] =
                        baseMask[p] ^ getBit(s[u]);
                } else {
                    baseMask[u] = getBit(s[u]);
                }

                st.push_back({u, p, 1});

                for (int v : adj[u]) {
                    if (v != p) {
                        st.push_back({v, u, 0});
                    }
                }

            } else {
                tout[u] = timer - 1;
            }
        }

        // Build Binary Lifting table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<bool> answer;

        for (string &q : queries) {

            stringstream ss(q);

            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {

                char c;
                ss >> c;

                int delta = getBit(s[u]) ^ getBit(c);

                // Update entire subtree
                rangeUpdate(
                    tin[u],
                    tout[u],
                    delta,
                    n
                );

                s[u] = c;

            } else {

                ss >> v;

                int lca = LCA(u, v);

                int mask =
                    getPrefix(u) ^
                    getPrefix(v) ^
                    getBit(s[lca]);

                // At most one odd-frequency character
                answer.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return answer;
    }
};