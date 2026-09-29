class Solution {
public:
    int n, m;

    // failed[i][j] contains balances which we already know don't work
    vector<vector<unordered_set<int>>> failed;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {

        if (i >= n || j >= m)
            return false;

        // Current cell
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Invalid balance
        if (balance < 0)
            return false;

        // Cells remaining after current cell
        int remaining = (n - 1 - i) + (m - 1 - j);

        // Not enough ')' left to close all '('
        if (balance > remaining)
            return false;

        // Destination
        if (i == n - 1 && j == m - 1)
            return balance == 0;

        // Already tried this exact state
        if (failed[i][j].count(balance))
            return false;

        // Try DOWN
        if (solve(grid, i + 1, j, balance))
            return true;

        // Try RIGHT
        if (solve(grid, i, j + 1, balance))
            return true;

        // Both failed -> remember this state
        failed[i][j].insert(balance);

        return false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();

        // Path length must be even
        if ((n + m - 1) % 2)
            return false;

        // First character must be '('
        if (grid[0][0] == ')')
            return false;

        failed.resize(n);

        for (int i = 0; i < n; i++)
            failed[i].resize(m);

        return solve(grid, 0, 0, 0);
    }
};