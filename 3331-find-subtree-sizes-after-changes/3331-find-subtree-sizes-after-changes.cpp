class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
         int n = parent.size();

        // Step 1: Build the original tree
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // New parent array
        vector<int> newParent(n, -1);

        // Last visited ancestor for each character
        vector<int> last(26, -1);

        // Store previous last value for backtracking
        vector<int> previous(n, -1);

        // Iterative DFS with enter/exit states
        stack<pair<int, bool>> st;
        st.push({0, false});

        while (!st.empty()) {

            auto [node, exiting] = st.top();
            st.pop();

            int c = s[node] - 'a';

            if (!exiting) {

                // Find closest ancestor with same character
                previous[node] = last[c];

                if (last[c] != -1) {
                    newParent[node] = last[c];
                }
                else {
                    newParent[node] = parent[node];
                }

                // Update last visited node
                last[c] = node;

                // Exit event
                st.push({node, true});

                // Visit original children
                for (int child : adj[node]) {
                    st.push({child, false});
                }

            } 
            else {

                // Restore previous ancestor
                last[c] = previous[node];
            }
        }

        // Step 2: Build the modified tree
        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Step 3: Get traversal order
        vector<int> order;
        stack<int> dfs;

        dfs.push(0);

        while (!dfs.empty()) {

            int node = dfs.top();
            dfs.pop();

            order.push_back(node);

            for (int child : newAdj[node]) {
                dfs.push(child);
            }
        }

        // Step 4: Calculate subtree sizes
        vector<int> ans(n, 1);

        for (int i = n - 1; i > 0; i--) {

            int node = order[i];

            ans[newParent[node]] += ans[node];
        }

        return ans; 
    }
};