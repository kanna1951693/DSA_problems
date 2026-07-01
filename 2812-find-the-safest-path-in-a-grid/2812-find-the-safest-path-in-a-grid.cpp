class Solution {
private:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    safeness[r][c] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && safeness[nr][nc] == -1) {
                    safeness[nr][nc] = safeness[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<vector<int>> pq;
        vector<vector<int>> max_safe_path(n, vector<int>(n, -1));

        pq.push({safeness[0][0], 0, 0});
        max_safe_path[0][0] = safeness[0][0];

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            int current_safety = current[0];
            int r = current[1];
            int c = current[2];

            if (r == n - 1 && c == n - 1) {
                return current_safety;
            }
            if (current_safety < max_safe_path[r][c]) {
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int next_safety = min(current_safety, safeness[nr][nc]);
                    if (next_safety > max_safe_path[nr][nc]) {
                        max_safe_path[nr][nc] = next_safety;
                        pq.push({next_safety, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};