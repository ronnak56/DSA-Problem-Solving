class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
  
        for (int i = 0; i < pre.size(); i++) {
            int a = pre[i][0];
            int b = pre[i][1];   // b -> a
            adj[b].push_back(a);
            indegree[a]++;
        }
        vector<int>ans;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
           ans.push_back(node);

            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }
        return ans.size() == n;
    }
};