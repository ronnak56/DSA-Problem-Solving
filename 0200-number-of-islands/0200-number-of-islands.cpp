class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = true;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;

            // top -> row-1, col
            if (r > 0) {
                if (!vis[r-1][c] && grid[r-1][c] == '1') {
                    vis[r-1][c] = true;
                    q.push({r-1, c});
                }
            }
            // bottom -> row+1, col
            if (r + 1 < n) {
                if (!vis[r+1][c] && grid[r+1][c] == '1') {
                    vis[r+1][c] = true;
                    q.push({r+1, c});
                }
            }
            // left -> row, col-1
            if (c > 0) {
                if (!vis[r][c-1] && grid[r][c-1] == '1') {
                    vis[r][c-1] = true;
                    q.push({r, c-1});
                }
            }
            // right -> row, col+1
            if (c + 1 < m) {
                if (!vis[r][c+1] && grid[r][c+1] == '1') {
                    vis[r][c+1] = true;
                    q.push({r, c+1});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};